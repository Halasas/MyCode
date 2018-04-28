package checked_expression;


import checked_expression.parser.ExpressionParser;

public class Main {
    public static void main(String[] args) throws ParserException,DivisionByZeroException,OverflowException,CountException {
        String s = "lol10";
        ExpressionParser parser = new ExpressionParser();
        TripleExpression exp = parser.parse(s);
        System.out.println(exp.evaluate(0,0,0));
    }
}
