package checked_expression;

public class CheckedVariable implements TripleExpression {
    private String var = "";

    public CheckedVariable(String var) {
        this.var = var;
    }

    public int evaluate(int x, int y, int z) throws CountException {
        if(var.equals("x"))
            return x;
        if(var.equals("y"))
            return y;
        else
            return z;
    }
}
