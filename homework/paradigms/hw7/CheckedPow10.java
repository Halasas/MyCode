package checked_expression;

public class CheckedPow10 extends CheckedUnaryOperation {

    public CheckedPow10(TripleExpression a) {
        super(a);
    }

    public int operation(int a) throws OverflowException,CountException {
        if (a > 9)
            throw new OverflowException("pow10(" + a + ')');
        else if (a < 0)
            throw new CountException("pow10(" + a + ')');
        int pow10 = 1;
        for (int i = 0; i < a; i++)
            pow10 *= 10;
        return pow10;
    }
}
