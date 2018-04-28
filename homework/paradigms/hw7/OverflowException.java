package checked_expression;

public class OverflowException extends Exception {
    public OverflowException(String message) {
        super("Overflow in: " + message);
    }
}