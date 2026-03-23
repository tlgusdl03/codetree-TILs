import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        HashSet<Integer> set1 = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();

        int n1 = sc.nextInt();

        int[] arr1 = new int[n1];
        for (int i = 0; i < n1; i++) {
            int tmp = sc.nextInt();
            arr1[i] = tmp;
            set1.add(tmp);
        }

        int n2 = sc.nextInt();

        int[] arr2 = new int[n2];
        for (int i = 0; i < n2; i++) {
            int tmp = sc.nextInt();
            arr2[i] = tmp;
            set2.add(tmp);
        }

        for (int i = 0; i < n2; i++) {
            if (set1.contains(arr2[i])) {
                System.out.print("1 ");
            }
            else {
                System.out.print("0 ");
            }
        }

        sc.close();
    }
}