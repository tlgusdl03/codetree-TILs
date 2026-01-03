import java.util.Scanner;

public class Main {
    public static final int MAX_N = 100;
    public static final int MAX_M = 10000;

    public static int n, m;
    public static int[] w = new int[MAX_N + 1];
    public static int[] v = new int[MAX_N + 1];
    public static int[][] dp = new int[MAX_N + 1][MAX_M + 1];

    public static int max(int a, int b) {
        return Math.max(a,b);
    }

    public static void initialize() {
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        
        for (int i = 1; i <= n; i++) {
            w[i] = sc.nextInt();
            v[i] = sc.nextInt();
        }
        
        initialize();

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);

                if (j >= w[i]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
                }
            }
        }

        System.out.print(dp[n][m]);
    }
}