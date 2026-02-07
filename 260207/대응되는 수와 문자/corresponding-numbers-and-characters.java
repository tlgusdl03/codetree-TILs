import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<String, String> hm = new HashMap<>();

        int n = sc.nextInt();
        int m = sc.nextInt();

        String[] words = new String[n + 1];
        for (int i = 1; i <= n; i++) {
            words[i] = sc.next();
        }
        
        sc.nextLine();

        for (int i = 1; i <= n; i++) {
            hm.put(words[i], Integer.toString(i));
            hm.put(Integer.toString(i), words[i]);
        }

        for (int i = 1; i <= m; i++) {
            String word = sc.nextLine();
            System.out.println(hm.get(word));
        }
        
        sc.close();

    }
}