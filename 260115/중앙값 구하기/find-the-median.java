import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();

        int MIN = 101;
        int MAX = -101;

        MIN = Math.min(MIN, A);
        MIN = Math.min(MIN, B);
        MIN = Math.min(MIN, C);

        MAX = Math.max(MAX, A);
        MAX = Math.max(MAX, B);
        MAX = Math.max(MAX, C);

        if (A != MIN && A != MAX) {
            System.out.print(A);
            return;
        }

        if (B != MIN && B != MAX) {
            System.out.print(B);
            return;
        }

        if (C != MIN && C != MAX) {
            System.out.print(C);
            return;
        }
    }
}