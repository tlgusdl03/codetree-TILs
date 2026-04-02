import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TreeSet<Integer> t = new TreeSet<>();

        int N, M;

        N = sc.nextInt();
        M = sc.nextInt();

        for (int i = 1; i <= M; i++) {
            t.add(i);
        }

        int tmp;
        for (int i = 0 ; i < N; i++) {
            tmp = sc.nextInt();
            t.remove(tmp);
            System.out.println(t.last());
        }

        
    }
}