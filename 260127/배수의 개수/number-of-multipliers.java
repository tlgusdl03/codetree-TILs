import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cnt_3 = 0;
        int cnt_5 = 0;
        int temp = 0;
        for (int i = 0; i < 10; i++) {
            temp = sc.nextInt();
            
            if (temp % 3 == 0) cnt_3++;
            if (temp % 5 == 0) cnt_5++;
        }

        System.out.print(cnt_3 + " " + cnt_5);
    }
}