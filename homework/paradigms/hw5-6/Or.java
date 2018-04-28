package expression;

public class Or extends AbstractBinaryOperation {

    public Or(TripleExpression a, TripleExpression b) {
        super(a, b);
    }

    public int operation(int a, int b) {
        return a | b;
    }
}
