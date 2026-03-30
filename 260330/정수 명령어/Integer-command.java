import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            int K = sc.nextInt();
            sc.nextLine();
            TreeSet<Integer> t = new TreeSet<>();

            for (int i = 0; i < K; i++) {
                String s = sc.nextLine();
                String[] token = s.split(" ");
                String cmd = token[0];
                Integer n = Integer.parseInt(token[1]);

                switch(cmd) {
                    case "I":
                        t.add(n);
                        break;
                    case "D":
                        if(t.isEmpty()) continue;
                        
                        if (n == 1) {
                            t.remove(t.last());
                        } 
                        else {
                            t.remove(t.first());
                        }

                        break;
                }
            }

            if (t.isEmpty()) {
                System.out.println("EMPTY");
            }
            else {
                System.out.println(t.last() + " " + t.first());
            }
        }

        sc.close();
    }
}