import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        HashSet<Integer> h = new HashSet<>();
        int cnt = 0;

        int n = sc.nextInt();
        
        for (int i = 0; i < n; i++) {
            int tmp = sc.nextInt();

            if (!h.contains(tmp)) {
                h.add(tmp);
                cnt++;
            }
        }

        System.out.println(cnt);
        sc.close();
    }
}