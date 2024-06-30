import java.security.MessageDigest;
import java.util.Scanner;

public class prog9{
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the text:");
        String text = sc.nextLine();
        MessageDigest md = MessageDigest.getInstance("SHA-512");
        byte[] hashbytes = md.digest(text.getBytes("UTF-8"));
        StringBuilder hexstring = new StringBuilder();
        for(byte hash: hashbytes){
            String hex = Integer.toHexString(0xff&hash);
            if(hex.length()==1) hexstring.append('0');
            hexstring.append(hex);
        }
        System.out.println("hashed:"+hexstring.toString());
    }
}