import java.security.MessageDigest;
import java.util.Scanner;
public class prog10{

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the text to hash: ");
        String text = scanner.nextLine();
        MessageDigest md = MessageDigest.getInstance("MD5");
        byte[] hashbytes = md.digest(text.getBytes());
        StringBuilder hexString = new StringBuilder();
        for (byte hash : hashbytes) {
            String hex = Integer.toHexString(0xff & hash);
            if (hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        System.out.println("MD5 Hash: " + hexString.toString());
}
}