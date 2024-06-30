import java.util.Scanner;
import java.util.Random;
import java.math.BigInteger;

public class prog7{
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("First prime number:");
        BigInteger p = sc.nextBigInteger();

        System.out.println("Second prime number:");
        BigInteger q = sc.nextBigInteger();

        BigInteger n = p.multiply(q);

        BigInteger phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));

        BigInteger e = GenerateE(phi);

        BigInteger d = e.modInverse(phi);

        System.out.println(e+","+n);
        System.out.println(d+","+n);

    }
    public static BigInteger GenerateE(BigInteger phi){
        Random rand = new Random();
        BigInteger e;

        do{
            e = new BigInteger(phi.bitLength(),rand);
        }while(e.compareTo(BigInteger.TWO)<=0||e.compareTo(phi)>=0|| !e.gcd(phi).equals(BigInteger.ONE));
        return e;
    }
}