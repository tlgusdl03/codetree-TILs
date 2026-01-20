import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String line = sc.nextLine();
        String[] parts = line.split(" ");
        String a = parts[0];
        String b = parts[1];

        if (a.length() > b.length()) {
            System.out.print(a + " " + a.length());
        }
        else if (a.length() < b.length()) {
            System.out.print(b + " " + b.length());
        }
        else {
            System.out.print("same");
        }

        sc.close();
    }
}