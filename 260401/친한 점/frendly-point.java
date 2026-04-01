import java.util.*;

class Pair implements Comparable<Pair> {
    int x, y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair p) {
        if(this.x == p.x) {
            return Integer.compare(this.y, p.y);
        }
        else {
            return Integer.compare(this.x, p.x);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        TreeSet<Pair> t = new TreeSet<>();

        int N = sc.nextInt();
        int M = sc.nextInt();

        int x, y;
        for (int i = 0; i < N; i++) {
            x = sc.nextInt();
            y = sc.nextInt();

            t.add(new Pair(x, y));
        }

        for (int i = 0 ; i < M; i++) {
            x = sc.nextInt();
            y = sc.nextInt();

            Pair p = t.ceiling(new Pair(x, y));
            System.out.println(p == null ? "-1 -1" : p.x + " " + p.y);
        }

        sc.close();
    }
}