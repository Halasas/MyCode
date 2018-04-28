package checked_expression;

public class CheckedAdd extends CheckedBinaryOperation {

    public CheckedAdd(TripleExpression a, TripleExpression b) {
        super(a, b);
    }

    public int operation(int a, int b) throws OverflowException {
        if ((a >= 0 && b <= 2147483647 - a) || (a <= 0 && b >= -2147483648 - a))
            return a + b;
        else throw new OverflowException(a + " + " + b);
    }
}
