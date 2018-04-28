package expression;

public abstract class AbstractBinaryOperation implements TripleExpression {
    private final TripleExpression a, b;

    public AbstractBinaryOperation(TripleExpression a, TripleExpression b) {
        this.a = a;
        this.b = b;
    }

    protected abstract int operation(int a, int b);
    public int evaluate(int x, int y, int z) { return operation(a.evaluate(x,y,z), b.evaluate(x,y,z));}
}
