package expression;

public class And extends AbstractBinaryOperation {

    public And(TripleExpression a, TripleExpression b) {
        super(a, b);
    }

    public int operation(int a, int b) {
        return a & b;
    }
}
