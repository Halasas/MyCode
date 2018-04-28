import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class SHA256Sum {
    public static String calcHexHash(MessageDigest digest, byte[] bytes) {
        StringBuilder hexHash = new StringBuilder();
        byte[] binaryHash = digest.digest(bytes);
        for (byte i : binaryHash)
            hexHash.append(String.format("%02x", i));
        return hexHash.toString();
    }

    public static void main(String[] args) {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            if (args.length != 0) {
                for (String file : args) {
                    byte[] bytes = Files.readAllBytes(Paths.get(file));
                    String hash = calcHexHash(digest, bytes);
                    System.out.println(hash + " *" + file);
                }
            } else {
                byte[] bytes = System.in.readAllBytes();
                String hash = calcHexHash(digest, bytes);
                System.out.println(hash + " *-");
            }
        } catch (NoSuchAlgorithmException e) {
            System.out.println("Error: Algorithm not found");
        } catch (FileNotFoundException e) {
            System.out.println("Error: File not found " + e.getMessage());
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}