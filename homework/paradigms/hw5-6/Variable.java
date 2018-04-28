package expression;

public class Variable implements TripleExpression {
    private String var = "";

    public Variable(String var) {
        this.var = var;
    }

    public int evaluate(int x, int y, int z) {
        if(var.equals("x"))
            return x;
        if(var.equals("y"))
            return y;
        if(var.equals("z"))
            return z;
        return 0;
    }
}
