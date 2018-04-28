package checked_expression;

public class CheckedMultiply extends CheckedBinaryOperation {

    public CheckedMultiply(TripleExpression a, TripleExpression b) {
        super(a, b);
    }

    public int operation(int a, int b) throws OverflowException {
        if (b <= 0 || ( -2147483648 / b <= a && a <= 2147483647 / b)) {
            if (b < -1 && (a > -2147483648 / b || a < 2147483647 / b))
                throw new OverflowException(a + " * " + b);
            else if (b == -1 && a == -2147483648)
                throw new OverflowException(a + " * " + b);
            else
                return a * b;
        } else throw new OverflowException(a + " * " + b);

    }
}
