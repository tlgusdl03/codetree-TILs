import java.util.*;
import java.util.Map.Entry;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        TreeMap<String, Integer> m = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            String word = sc.nextLine();

            m.put(word, m.getOrDefault(word, 0) + 1);
        }

        Iterator<Entry<String, Integer>> it = m.entrySet().iterator();

        while(it.hasNext()) {
            Entry entry = it.next();

            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
}