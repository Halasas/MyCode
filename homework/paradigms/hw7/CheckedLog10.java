package checked_expression;

public class CheckedLog10 extends CheckedUnaryOperation {

    public CheckedLog10(TripleExpression a) {
        super(a);
    }

    public int operation(int a) throws OverflowException, CountException {
        if (a <= 0)
            throw new CountException("does not exist log10(" + a + ')');
        int log10 = 0;
        int x = a;
        while (x >= 10) {
            log10++;
            x /= 10;
        }
        return log10;
    }
}
