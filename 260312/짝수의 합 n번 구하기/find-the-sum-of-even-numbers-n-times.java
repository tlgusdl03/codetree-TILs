import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            int sum = 0;

            for (int j = a; j <= b; j++) {
                if (j % 2 == 0) {
                    sum += j;
                }
            }

            System.out.println(sum);
        }

        sc.close();
    }
}