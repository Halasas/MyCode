package checked_expression;

public class CheckedDivide extends CheckedBinaryOperation {

    public CheckedDivide(TripleExpression a, TripleExpression b) {
        super(a, b);
    }

    public int operation(int a, int b) throws OverflowException, DivisionByZeroException {
        if (a == -2147483648 && b == -1)
            throw new OverflowException(a + "/" + b);
        else if (b == 0)
            throw new DivisionByZeroException(a + "/" + b);
        else return a / b;
    }
}
