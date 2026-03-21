import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();

        HashSet<Integer> h = new HashSet<>();

        for (int i = 0; i < n; i++) {
            String input = sc.nextLine();
            String[] cmd = input.split(" ");
            String command = cmd[0];
            int x = Integer.parseInt(cmd[1]);

            if (command.equals("add")) {
                h.add(x);
            }
            else if (command.equals("remove")) {
                h.remove(x);
            }
            else if (command.equals("find")) {
                if (h.contains(x)) {
                    System.out.println("true");
                }
                else {
                    System.out.println("false");
                }
            }
        }
    }
}