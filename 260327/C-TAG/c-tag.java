import java.util.*;

// A그룹과 B그룹에서 각각 3중 for문을 돌려 나올 수 있는 모든 경우의 수를 구함
// 이후 A그룹에서 나온 경우와 B그룹에서 나온 경우가 모두 다른 경우만 카운트함
// O(M^3 * N)
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.nextLine();

        String[] groupA = new String[N];
        String[] groupB = new String[N];

        for (int i = 0; i < N; i++) {
            groupA[i] = sc.nextLine();
        }

        for (int i = 0; i < N; i++) {
            groupB[i] = sc.nextLine();
        }

        int ans = 0;

        for (int i = 0; i < M - 2; i++) {
            for (int j = i + 1; j < M - 1; j++) {
                for (int k = j + 1; k < M; k++) {
                    HashSet<String> hA = new HashSet<>();
                    HashSet<String> hB = new HashSet<>();

                    for (int l = 0; l < N; l++) {
                        String tmpA = "" + groupA[l].charAt(i) + groupA[l].charAt(j) + groupA[l].charAt(k);
                        String tmpB = "" + groupB[l].charAt(i) + groupB[l].charAt(j) + groupB[l].charAt(k);

                        hA.add(tmpA);
                        hB.add(tmpB);
                    }

                    Iterator<String> itA = hA.iterator();
                    boolean distinct = true;

                    while(itA.hasNext()) {
                        String wordA = itA.next();
                        if (hB.contains(wordA)) {
                            distinct = false;
                            break;
                        }
                    }

                    if (distinct) ans++;
                }
            }
        }

        System.out.println(ans);
        sc.close();
    }
}

