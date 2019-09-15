
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/03/27
 *
 * @author dezhonger
 * @since 2019/03/27
 */
public class Leetcode996 {


    static int cnt = 0;
    static Set<Integer> set = new HashSet<>();


    private static void dfs(int index, int[] a, boolean[] b, ArrayList<Integer> list) {
        if (index == a.length) {
            for (int i = 1; i < index; i++) {
                if (!set.contains(list.get(i) + list.get(i - 1))) {
                    return;
                }
            }
            cnt++;
            return;
        }
        int last = -1;
        for (int i = 0; i < a.length; i++) {
            if (!b[i]) {
                if (a[i] != last) {
                    last = a[i];
                    if(index ==0 || set.contains(a[i] + list.get(list.size() - 1)))  {
                        list.add(a[i]);
                        b[i] = true;
                        dfs(index + 1, a, b, list);
                        list.remove(list.size() - 1);
                        b[i] = false;
                    }

                }

            }
        }

    }

    public int numSquarefulPerms(int[] A) {
        if (A.length == 1) return 0;
        cnt = 0;
        set.clear();
        for (int i = 0; i < A.length; i++) {
            for (int j = i + 1; j < A.length; j++) {
                int x = A[i] + A[j];
                int y = (int) Math.sqrt(x);
                if (y * y == x) {
                    set.add(x);
                }
            }
        }
        Arrays.sort(A);
        boolean[] b = new boolean[A.length];
        dfs(0, A, b, new ArrayList<>());

        return cnt;
    }


}
