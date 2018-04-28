package expression;

public class Xor extends AbstractBinaryOperation {

    public Xor(TripleExpression a, TripleExpression b) {
        super(a, b);
    }

    public int operation(int a, int b) {
        return a ^ b;
    }
}
