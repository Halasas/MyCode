package expression;

public class Subtract extends AbstractBinaryOperation {

    public Subtract(TripleExpression a, TripleExpression b) {
        super(a, b);
    }

    public int operation(int a, int b) {
        return a - b;
    }
}
