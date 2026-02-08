import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr = new int[n];
        Map<Integer, Integer> hm = new HashMap<>();

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            hm.put(arr[i], hm.getOrDefault(arr[i], 0) + 1);
        }

        int cnt = 0;

        for (int i = 0; i < n / 2; i++) {
            int x = arr[i];

            if (hm.containsKey(k - x)) {
                cnt += hm.get(k - x);
            }

            if (k - x == x) {
                cnt--;
            }
        }

        System.out.print(cnt);
    }
}