import java.util.Scanner;
public class Main {

    public static final int MAX_N = 100;
    public static int n;
    public static int[] profit = new int[MAX_N + 1];
    public static int[][] dp = new int[MAX_N + 1][MAX_N + 1];

    public static void initialize() {
        for (int i = 0; i <= MAX_N; i++) {
            for (int j = 0; j <= MAX_N; j++) {
                dp[i][j] = 0;
            }
        }
    }

    public static void solve() {
        initialize();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];

                if (j >= i) {
                    dp[i][j] = Math.max(dp[i][j], dp[i][j - i] + profit[i]);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        
        for (int i = 1; i <= n; i++) {
            profit[i] = sc.nextInt();
        }
        
        solve();

        System.out.print(dp[n][n]);
    }
}