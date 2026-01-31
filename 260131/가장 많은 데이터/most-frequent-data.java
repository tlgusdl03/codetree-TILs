import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        HashMap<String, Integer> HM = new HashMap<>();

        int n = sc.nextInt();
        int MAX = 0;

        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.next();
        }

        for (int i = 0; i < n; i++) {
            HM.put(arr[i], 0);
        }

        for (int i = 0; i < n; i++) {
            int prev = HM.get(arr[i]);
            HM.put(arr[i], prev + 1);
            MAX = Math.max(MAX, prev + 1);
        }

        System.out.print(MAX);
    }
}