import java.io.*;
import java.math.*;
import java.nio.file.*;
import java.security.*;

public class CalcMD5 {
    public static String md5(byte[] bytes) {
        String Hex = "";
        try {
            MessageDigest digest = MessageDigest.getInstance("md5");
            byte[] encodedhash = digest.digest(bytes);
            BigInteger Dec = new BigInteger(1, encodedhash);
            Hex = Dec.toString(16);
            Hex = Hex.toUpperCase();
            while (Hex.length() < 32)
                Hex = "0" + Hex;
        } catch (NoSuchAlgorithmException e) {
            System.out.println("ERROR: MD5 does not work :с");
        }
        return Hex;
    }

    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(args[0]), "UTF-8"))) {
            String file;
            while ((file = reader.readLine()) != null) {
                byte[] bytes = Files.readAllBytes(Paths.get(file));
                String hash = md5(bytes);
                System.out.println(hash);
            }
        } catch (UnsupportedEncodingException e) {
            System.out.println("ERROR: uncorrected encoding :с" + e.getMessage());
        } catch (FileNotFoundException e) {
            System.out.println("ERROR: input file not found :с" + e.getMessage());
        } catch (IOException e) {
            System.out.println("ERROR: input error :с" + e.getMessage());
        }
    }
}