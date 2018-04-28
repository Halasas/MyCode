package expression;

public class Divide extends AbstractBinaryOperation {

    public Divide(TripleExpression a, TripleExpression b) {
        super(a, b);
    }

    public int operation(int a, int b) {
        return a / b;
    }
}
