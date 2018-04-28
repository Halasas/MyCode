package checked_expression;

public class CheckedSubtract extends CheckedBinaryOperation {

    public CheckedSubtract(TripleExpression a, TripleExpression b) {
        super(a, b);
    }

    public int operation(int a, int b) throws OverflowException {
        if ((a >= 0 && b >= a - 2147483647) || (a < 0 && b <= a - (-2147483648)))
            return a - b;
        else throw new OverflowException(a + " - " + b);
    }
}
