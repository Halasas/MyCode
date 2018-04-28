package expression;

public abstract class AbstractUnaryOperation implements TripleExpression {
    private final TripleExpression a;

    public AbstractUnaryOperation(TripleExpression a) {
        this.a = a;
    }

    protected abstract int operation(int a);
    public int evaluate(int x, int y, int z) { return operation(a.evaluate(x,y,z));}
}
