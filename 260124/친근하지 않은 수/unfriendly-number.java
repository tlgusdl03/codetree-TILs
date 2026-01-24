import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int cnt = 0;
        int N = sc.nextInt();

        for (int i = 1; i <= N; i++) {
            if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0) cnt++;
        }

        System.out.print(cnt);

        sc.close();
    }
}