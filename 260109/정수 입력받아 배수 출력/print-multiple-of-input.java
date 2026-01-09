import java.util.*;

public class Main {
    static int N;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        for (int i = 1; i <= 5; i++) {
            System.out.print(N * i + " ");
        }
    }
}