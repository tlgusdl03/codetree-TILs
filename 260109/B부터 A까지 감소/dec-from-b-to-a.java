import java.util.*;
public class Main {
    static int A, B;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        A = sc.nextInt();
        B = sc.nextInt();

        for (int i = B; i >= A; i--) {
            System.out.print(i + " ");
        }
    }
}