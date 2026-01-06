import java.util.Scanner;
public class Main {

    public static final int MAX_N = 100000;
    public static int n;
    public static int[] nums = new int[MAX_N];
    public static int[] dp = new int[MAX_N];
    public static final int MIN = Integer.MIN_VALUE;
    public static int ans = MIN;

    public static void initialize() {
        for (int i = 0; i < MAX_N; i++) {
            dp[i] = MIN;
        }
        dp[0] = nums[0];
    }

    public static void solve() {
        initialize();

        for (int i = 1; i < n; i++) {
            dp[i] = Math.max(dp[i - 1] + nums[i], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, dp[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        solve();

        System.out.println(ans);
    }
}