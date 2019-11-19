
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 * Created by dezhonger on 2019/11/20
 *
 * @author dezhonger
 * @since 2019/11/20
 */
public class Leetcode1260 {
    public static void main(String[] args) {
        Leetcode1260 l = new Leetcode1260();
        int[][] a = new int[][]{
                {1},
                {2},
                {3},
                {4},
                {7},
                {6},
                {5},
        };
        l.shiftGrid(a, 23);
    }

    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        Map<Integer, Integer> map = new HashMap<>();
        Map<Integer, Integer> map2 = new HashMap<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int t = i * n + j;
                map.put(t, grid[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int t = i * n + j;
                int x = map.get(t);
                int tt = (t + k) % (m * n);
                map2.put(tt, x);
            }
        }
        List<List<Integer>> r = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> l = new LinkedList<>();
            for (int j = 0; j < n; j++) {
                int t = i * n + j;
                int x = map2.get(t);
                l.add(x);

            }
            r.add(l);
        }
        return r;
    }
}
