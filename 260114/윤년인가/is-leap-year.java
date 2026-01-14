import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int Y = sc.nextInt();

        if (Y % 100 == 0 && Y % 400 != 0) System.out.print("false");
        
        else if (Y % 4 == 0) System.out.print("true");
        else System.out.print("false");
    }
}