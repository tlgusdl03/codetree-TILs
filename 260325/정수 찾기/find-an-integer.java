import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        HashSet<Integer> h1 = new HashSet<>();

        for (int i = 0; i < n1; i++) {
            int tmp = sc.nextInt();
            h1.add(tmp);
        }

        int n2 = sc.nextInt();
        HashSet<Integer> h2 = new HashSet<>();

        for (int i = 0; i < n2; i++) {
            int tmp = sc.nextInt();
            if (h1.contains(tmp)) {
                System.out.println("1");
            }
            else {
                System.out.println("0");
            }
        }

        sc.close();
    }
}