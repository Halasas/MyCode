package checked_expression;

public class DivisionByZeroException extends Exception {
    public DivisionByZeroException(String message) {
        super("Division by zero: " + message);
    }
}
