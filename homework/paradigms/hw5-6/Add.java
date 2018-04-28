package expression;

public class Add extends AbstractBinaryOperation {

    public Add(TripleExpression a, TripleExpression b) {
        super(a, b);
    }

    public int operation(int a, int b) {
        return a + b;
    }
}
