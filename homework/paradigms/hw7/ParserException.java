package checked_expression;

public class ParserException extends Exception {
    public ParserException(String message) {
        super("Parsing error: " + message);
    }
}

