import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        HashMap<Integer, Integer> m = new HashMap<>();

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            String cmd = parts[0];
            int a = Integer.parseInt(parts[1]);

            if (cmd.equals("add")) {
                int b = Integer.parseInt(parts[2]);
                m.put(a, b);
            }
            else if (cmd.equals("remove")) {
                m.remove(a);
            }
            else if (cmd.equals("find")) {
                if (!m.containsKey(a)) {
                    System.out.println("None");
                }
                else {
                    System.out.println(m.get(a));
                }
            }
        }
        sc.close();
    }
}