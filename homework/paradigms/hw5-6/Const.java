package expression;

public class Const implements TripleExpression {

    private final Number con;

    public Const(int input) {
        this.con = input;
    }

    public int evaluate(int x, int y, int z) {
        return con.intValue();
    }

}