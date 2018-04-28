package checked_expression.parser;

import checked_expression.*;

public class ExpressionParser implements Parser {
    private String exp = "";
    private int len = 0;
    private int pos = 0;
    private int balance = 0;

    public TripleExpression parse(String s) throws ParserException {
        this.exp = s;
        this.len = s.length();
        this.pos = 0;
        TripleExpression res = this.parseAddSub();
        if (this.pos < this.len)
            throw new ParserException(getCheckerMessage());
        else return res;
    }

    private String getCheckerMessage() {
        if (this.pos >= this.len && balance > 0)
            return "bracket not closed : '" + this.exp + "'";
        else if (this.pos < this.len && this.exp.charAt(this.pos) == ')' && balance == 0)
            return "bracket not opened : '" + this.exp + "'";
        else if (this.pos >= this.len || this.exp.charAt(this.pos) == ')' || this.exp.charAt(this.pos) == '*' || this.exp.charAt(this.pos) == '/' || this.exp.charAt(this.pos) == '+' || this.exp.charAt(this.pos) == '-')
            return "expected variable or constant at pos " + this.pos + " in '" + this.exp.substring(0,this.pos) + " >HERE< " + this.exp.substring(this.pos) + "'";
        else
            return "unexpected symbol: '" + this.exp.charAt(this.pos) + "' in '" + this.exp.substring(0,this.pos) + " >HERE> " + this.exp.substring(this.pos) + "'";
    }

    private void toNext() { // move pos to next operand
        while (this.pos < this.len &&
                Character.isWhitespace(this.exp.charAt(this.pos)))
            this.pos++;
    }


    private TripleExpression parseAddSub() throws ParserException { // + -
        TripleExpression left = parseMulDiv();
        while (this.pos < this.len) {
            char sign = this.exp.charAt(this.pos);
            if (sign != '+' && sign != '-')
                return left;
            this.pos++;
            this.toNext();
            TripleExpression right = this.parseMulDiv();
            if (sign == '+')
                left = new CheckedAdd(left, right);
            else
                left = new CheckedSubtract(left, right);
        }
        return left;
    }

    private TripleExpression parseMulDiv() throws ParserException { // * /
        TripleExpression left = parseRB();
        while (this.pos < this.len) {
            char sign = this.exp.charAt(this.pos);
            if (sign != '*' && sign != '/')
                return left;
            this.pos++;
            this.toNext();
            TripleExpression right = this.parseRB();
            if (sign == '*') {
                left = new CheckedMultiply(left, right);
            } else {
                left = new CheckedDivide(left, right);
            }
        }
        return left;
    }

    private TripleExpression parseRB() throws ParserException { // ( )
        this.toNext();
        if (this.pos < this.len) {
            if (this.exp.charAt(this.pos) != '(')
                return this.parseVarOrConst();
            balance++;
            this.pos++;
            this.toNext();
            TripleExpression right = this.parseAddSub();
            if (this.pos < this.len && this.exp.charAt(this.pos) == ')') {
                balance--;
                this.pos++;
                this.toNext();
                return right;
            } else throw new ParserException(getCheckerMessage());
        }
        return this.parseVarOrConst();
    }

    private TripleExpression parseVarOrConst() throws ParserException {
        TripleExpression res;
        if (this.pos < this.len - 1 && this.exp.charAt(this.pos) == '-' && !Character.isDigit(this.exp.charAt(this.pos + 1))) {
            this.pos++;
            this.toNext();
            res = new CheckedUnaryMinus(this.parseRB());
        } else {
            StringBuilder tmp = new StringBuilder("");
            if (this.pos >= this.len)
                throw new ParserException(getCheckerMessage());
            if (this.exp.charAt(this.pos) == '-') {
                tmp.append('-');
                this.pos++;
            }
            while (this.pos < this.len && (Character.isLetter(this.exp.charAt(this.pos)) || Character.isDigit(this.exp.charAt(this.pos))))
                tmp.append(this.exp.charAt(this.pos++));
            this.toNext();

            if (tmp.toString().isEmpty())
                throw new ParserException(getCheckerMessage());
            if (tmp.toString().equals("log10"))
                res = new CheckedLog10(this.parseRB());
            else if (tmp.toString().equals("pow10"))
                res = new CheckedPow10(this.parseRB());
            else if (Character.isDigit(tmp.charAt(0)) || tmp.charAt(0) == '-')
                try {
                    res = new CheckedConst(Integer.parseInt(tmp.toString()));
                } catch (NumberFormatException e) {
                    throw new ParserException("Unsupported number format : " + tmp.toString());
                }
            else if (tmp.toString().equals("x") || tmp.toString().equals("y") || tmp.toString().equals("z"))
                res = new CheckedVariable(tmp.toString());
            else throw new ParserException("unknown variable or function '" + tmp + "'");
        }
        return res;
    }
}
