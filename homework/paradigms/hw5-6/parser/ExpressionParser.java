package expression.parser;

import expression.*;

public class ExpressionParser implements Parser {
    private String exp = "";
    private int len = 0;
    private int pos = 0;

    public TripleExpression parse(String s) {
        this.exp = s;
        this.len = s.length();
        this.pos = 0;
        return this.parseOr();
    }

    private void toNext() { // move pos to next operand
        while (this.pos < this.len &&
                Character.isWhitespace(this.exp.charAt(this.pos)))
            this.pos++;
    }

    private TripleExpression parseOr() { // |
        TripleExpression left = parseXor();
        while (this.pos < this.len) {
            char sign = this.exp.charAt(this.pos);
            if (sign != '|')
                return left;
            this.pos++;
            this.toNext();
            TripleExpression right = this.parseXor();
            left = new Or(left, right);
        }
        return left;
    }

    private TripleExpression parseXor() { // |
        TripleExpression left = parseAnd();
        while (this.pos < this.len) {
            char sign = this.exp.charAt(this.pos);
            if (sign != '^')
                return left;
            this.pos++;
            this.toNext();
            TripleExpression right = this.parseAnd();
            left = new Xor(left, right);
        }
        return left;
    }

    private TripleExpression parseAnd() { // |
        TripleExpression left = parseAddSub();
        while (this.pos < this.len) {
            char sign = this.exp.charAt(this.pos);
            if (sign != '&')
                return left;
            this.pos++;
            this.toNext();
            TripleExpression right = this.parseAddSub();
            left = new And(left, right);
        }
        return left;
    }

    private TripleExpression parseAddSub() { // + -
        TripleExpression left = parseMulDiv();
        while (this.pos < this.len) {
            char sign = this.exp.charAt(this.pos);
            if (sign != '+' && sign != '-')
                return left;
            this.pos++;
            this.toNext();
            TripleExpression right = this.parseMulDiv();
            if (sign == '+')
                left = new Add(left, right);
            else
                left = new Subtract(left, right);
        }
        return left;
    }

    private TripleExpression parseMulDiv() { // * /
        TripleExpression left = parseRB();
        while (this.pos < this.len) {
            char sign = this.exp.charAt(this.pos);
            if (sign != '*' && sign != '/')
                return left;
            this.pos++;
            this.toNext();
            TripleExpression right = this.parseRB();
            if (sign == '*') {
                left = new Multiply(left, right);
            } else {
                left = new Divide(left, right);
            }
        }
        return left;
    }

    private TripleExpression parseRB() { // ( )
        this.toNext();
        if (this.pos < this.len) {
            if (this.exp.charAt(this.pos) != '(')
                return this.parseVarOrConst();
            this.pos++;
            this.toNext();
            TripleExpression right = this.parseOr();
            this.pos++;
            this.toNext();
            return right;
        }
        return this.parseVarOrConst();
    }

    private TripleExpression parseVarOrConst() {
        TripleExpression res = new Const(0);
        if (this.pos < this.len - 1 && this.exp.charAt(this.pos) == '-' && !Character.isDigit(this.exp.charAt(this.pos + 1))) {
            this.pos++;
            this.toNext();
            res = new UnaryMinus(this.parseRB());
        } else {
            StringBuilder tmp = new StringBuilder("");
            if (this.exp.charAt(this.pos) == '-') {
                tmp.append('-');
                this.pos++;
            }
            while (this.pos < this.len && (Character.isLetter(this.exp.charAt(this.pos)) || Character.isDigit(this.exp.charAt(this.pos))))
                tmp.append(this.exp.charAt(this.pos++));
            this.toNext();

            if (Character.isDigit(tmp.charAt(0)) || tmp.charAt(0) == '-') {
                res = new Const(Integer.parseInt(tmp.toString()));
            }
            if (Character.isLetter(tmp.charAt(0))) {
                res = new Variable(tmp.toString());
            }
        }
        return res;
    }
}
