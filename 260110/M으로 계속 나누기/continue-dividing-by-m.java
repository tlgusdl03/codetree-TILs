import java.util.Scanner;

public class Main {
    public static int N, M;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        
        while (N > 0) {
            System.out.println(N);
            N /= M;
        }
    }
}
