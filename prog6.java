import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.Cipher;
import java.util.Base64;

public class prog6{
    public static SecretKey GenerateKey(int n) throws Exception{
        KeyGenerator keyGenerator = KeyGenerator.getInstance("AES");
        keyGenerator.init(n);
        SecretKey secretKey = keyGenerator.generateKey();
        return secretKey;
    }

    public static String Encrypt(String plainText, SecretKey secretKey) throws  Exception{
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encrypted = cipher.doFinal(plainText.getBytes());
        return Base64.getEncoder().encodeToString(encrypted);
    }

    public static String Decrypt(String Encrypted, SecretKey secretKey) throws Exception{
        Cipher cipher = Cipher.getInstance("AES");
        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decrypted = cipher.doFinal(Base64.getDecoder().decode(Encrypted));
        return new String(decrypted);

    }

    public static void main(String[] args) {
       try {
            String plainText = "This is my secret key!";
            SecretKey secretKey = GenerateKey(128);
            String encrypted = Encrypt(plainText, secretKey);
            System.out.println(encrypted);
            String decrypted = Decrypt(encrypted, secretKey);
            System.out.println(decrypted);
        }catch (Exception e){
           e.printStackTrace();
       }
    }
}