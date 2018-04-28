package expression;

public class UnaryMinus extends AbstractUnaryOperation {

    public UnaryMinus(TripleExpression a) {
        super(a);
    }

    public int operation(int a) {
        return -a;
    }
}
