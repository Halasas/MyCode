package checked_expression;

public abstract class CheckedUnaryOperation implements TripleExpression {
    private final TripleExpression a;

    public CheckedUnaryOperation(TripleExpression a) {
        this.a = a;
    }

    protected abstract int operation(int a) throws OverflowException, DivisionByZeroException, CountException;
    public int evaluate(int x, int y, int z) throws OverflowException, DivisionByZeroException, CountException { return operation(a.evaluate(x,y,z));}
}
