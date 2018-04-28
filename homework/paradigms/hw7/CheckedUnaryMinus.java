package checked_expression;

public class CheckedUnaryMinus extends CheckedUnaryOperation {

    public CheckedUnaryMinus(TripleExpression a) {
        super(a);
    }

    public int operation(int a) throws OverflowException {
        if (a != -2147483648)
            return -a;
        else throw new OverflowException("-(" + a + ")");
    }
}
