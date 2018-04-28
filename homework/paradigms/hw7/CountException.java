package checked_expression;

public class CountException extends Exception {
    public CountException(String message) {
        super("Counting error: " + message);
    }
}
