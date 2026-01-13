import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int s = sc.nextInt();
        int age = sc.nextInt();

        String result = "";

        if (s == 0) {
            if (age >= 19) {
                result = "MAN";
            }
            else {
                result = "BOY";
            }
        }
        else if (s == 1) {
            if (age >= 19) {
                result = "WOMAN";
            }
            else {
                result = "GIRL";
            }
        }

        System.out.print(result);
    }
}