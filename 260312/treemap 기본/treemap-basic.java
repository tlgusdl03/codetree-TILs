import java.util.Scanner;
import java.util.TreeMap;
import java.util.Iterator;
import java.util.Map.Entry;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        TreeMap<Integer, Integer> m = new TreeMap<>();

        for (int i = 0; i < n; i++) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            String cmd = parts[0];

            if (cmd.equals("print_list")) {
                if (m.isEmpty()) {
                    System.out.println("None");
                }
                else {
                    Iterator<Entry<Integer, Integer>> it = m.entrySet().iterator();
                    while(it.hasNext()) {
                        Entry<Integer, Integer> entry = it.next();
                        System.out.print(entry.getValue() + " ");
                    }
                    System.out.println();
                }
                continue;
            }

            int k = Integer.parseInt(parts[1]);

            if (cmd.equals("add")) {
                int v = Integer.parseInt(parts[2]);
                m.put(k, v);
            }
            else if (cmd.equals("remove")) {
                if (m.containsKey(k)) m.remove(k);
            }
            else if (cmd.equals("find")) {
                if (m.containsKey(k)) {
                    int v = m.get(k);
                    System.out.println(v);
                }
                else {
                    System.out.println("None");
                }
            }
            else {
                System.out.println("잘못된 입력!");
                return;
            }
        }
    }
}