import java.util.Scanner;
import java.util.TreeMap;
import java.util.Iterator;
import java.util.Map.Entry;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        TreeMap<String, Integer> tm = new TreeMap<>();
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.next();

            tm.put(arr[i], tm.getOrDefault(arr[i], 0) + 1);
        }
        
        Iterator<Entry<String, Integer>> it = tm.entrySet().iterator();

        while(it.hasNext()) {
            Entry<String, Integer> entry = it.next();
            double ratio = (double) entry.getValue() / n * 100;
            System.out.println(entry.getKey() + " " + String.format("%.4f", ratio));
        }
    }
}