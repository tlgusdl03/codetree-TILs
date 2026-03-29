import java.util.TreeSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        TreeSet<Integer> t = new TreeSet<>();
        int N = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < N; i++) {
            String s = sc.nextLine();
            String[] token = s.split(" ");
            String cmd = token[0];

            Integer x;

            switch (cmd) {
                case "add":
                    x = Integer.parseInt(token[1]);
                    t.add(x);
                    break;
                case "remove":
                    x = Integer.parseInt(token[1]);
                    t.remove(x);
                    break;
                case "find":
                    x = Integer.parseInt(token[1]);
                    System.out.println(t.contains(x) ? "true" : "false");
                    break;
                case "lower_bound":
                    x = Integer.parseInt(token[1]);
                    Integer ceiling = t.ceiling(x);
                    System.out.println(ceiling == null ? "None" : ceiling);
                    break;
                case "upper_bound":
                    x = Integer.parseInt(token[1]);
                    Integer higher = t.higher(x);
                    System.out.println(higher == null ? "None" : higher);
                    break;
                case "largest":
                    if (t.isEmpty()) {
                        System.out.println("None");
                    } else {
                        System.out.println(t.last());
                    }
                    break;
                case "smallest":
                    if (t.isEmpty()) {
                        System.out.println("None");
                    } else {
                        System.out.println(t.first());
                    }
                    break;
            }
        }
        sc.close();
    }
}