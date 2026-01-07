import java.util.Scanner;
public class Main {
    public static final int MAX_N = 1000;
    public static final int MAX_HOP = 3;
    public static final int INT_MIN = Integer.MIN_VALUE;
    public static int[][] dp = new int[MAX_N + 1][MAX_HOP + 1];
    public static int[] coins = new int[MAX_N + 1];
    public static int n = 0;
    public static int ans = 0;
    
    public static void initialize() {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= MAX_HOP; j++) {
                dp[i][j] = INT_MIN;
            }
        }
        dp[0][0] = 0;
    }
    
    public static void solve() {
        initialize();
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= MAX_HOP; j++) {
                // 1. dp[i - 2][j]
                // 2. dp[i - 1][j - 1]

                if (i > 1) dp[i][j] = Math.max(dp[i][j], dp[i - 2][j] + coins[i]);
                if (j > 0) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + coins[i]);
            }
        }

        for (int j = 0; j <= MAX_HOP; j++) {
            ans = Math.max(ans, dp[n][j]);
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        
        for (int i = 1; i <= n; i++) {
            coins[i] = sc.nextInt();
        }
        
        solve();

        System.out.println(ans);
    }
}