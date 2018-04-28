package checked_expression;

public class CheckedConst implements TripleExpression {

    private final Number con;

    public CheckedConst(int input) {
        this.con = input;
    }

    public int evaluate(int x, int y, int z) {
        return con.intValue();
    }

}