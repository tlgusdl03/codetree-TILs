import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        TreeSet<Integer> t = new TreeSet<>();
 
        for (int i = 0; i < n; i++) {
            int tmp = sc.nextInt();
            t.add(tmp);
        }

        for (int i = 0; i < m; i++) {
            int tmp = sc.nextInt();
            Integer result = t.ceiling(tmp);

            System.out.println(result == null ? -1 : result);
        }

        sc.close();
    }
}