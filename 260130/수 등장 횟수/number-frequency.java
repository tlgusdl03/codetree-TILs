import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<Integer, Integer> HM = new HashMap<>();

        int n = sc.nextInt();
        int m = sc.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int[] queries = new int[m];
        for (int i = 0; i < m; i++) {
            queries[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            HM.put(arr[i], 0);
        }

        for (int i = 0; i < n; i++) {
            int prev = HM.get(arr[i]);
            HM.put(arr[i], prev + 1);
        }

        for (int i = 0; i < m; i++) {
            if (HM.containsKey(queries[i])) {
                System.out.print(HM.get(queries[i]) + " ");
            }
            else {
                System.out.print(0 + " ");
            }
        }
        
        sc.close();
    }
}