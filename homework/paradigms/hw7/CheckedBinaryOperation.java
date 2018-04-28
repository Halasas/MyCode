package checked_expression;

public abstract class CheckedBinaryOperation implements TripleExpression {
    private final TripleExpression a, b;

    public CheckedBinaryOperation(TripleExpression a, TripleExpression b) {
        this.a = a;
        this.b = b;
    }

    protected abstract int operation(int a, int b)throws OverflowException, DivisionByZeroException, CountException;
    public int evaluate(int x, int y, int z) throws OverflowException, DivisionByZeroException, CountException { return operation(a.evaluate(x,y,z), b.evaluate(x,y,z));}
}
