
import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/11/24
 */
public class Leetcode1267 {

    int m, n;

    int hash(int r, int c) {
        return r * n + c;
    }

    public int countServers(int[][] grid) {
        Set<Integer> set = new HashSet<>();
        //row
        m = grid.length;
        //column
        n = grid[0].length;
        for (int i = 0; i < m; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) c++;
            }
            if (c > 1) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) set.add(hash(i, j));
                }
            }
        }


        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < m; j++) {
                if (grid[j][i] == 1) c++;
            }
            if (c > 1) {
                for (int j = 0; j < m; j++) {
                    if (grid[j][i] == 1) set.add(hash(j, i));
                }
            }
        }
        return set.size();
    }

}
