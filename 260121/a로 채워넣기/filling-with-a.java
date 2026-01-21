import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.nextLine();

        int len = str.length();

        StringBuilder sb = new StringBuilder(str);

        sb.setCharAt(1, 'a');
        sb.setCharAt(len - 2, 'a');

        System.out.print(sb.toString());
    }
}