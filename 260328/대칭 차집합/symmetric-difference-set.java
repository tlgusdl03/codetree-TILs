import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();

        int[] arrA = new int[A];
        HashSet<Integer> hA = new HashSet<>();
        for (int i = 0; i < A; i++) {
            arrA[i] = sc.nextInt();
            hA.add(arrA[i]);
        }

        int[] arrB = new int[B];
        HashSet<Integer> hB = new HashSet<>();
        for (int i = 0; i < B; i++) {
            arrB[i] = sc.nextInt();
            hB.add(arrB[i]);
        }

        for (int i = 0; i < A; i++) {
            if (hB.contains(arrA[i])) {
                hB.remove(arrA[i]);
            }
        }

        for (int i = 0; i < B; i++) {
            if (hA.contains(arrB[i])) {
                hA.remove(arrB[i]);
            }
        }

        System.out.println(hA.size() + hB.size());
        sc.close();
        
    }
}