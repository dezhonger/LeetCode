
import java.util.ArrayDeque;
import java.util.Queue;

/**
 * Created by dezhonger on 2019/05/07
 *
 * @author dezhonger
 * @since 2019/05/07
 * <p>
 * n,m<=10
 */
public class Solution {



    private int m, n;
    private int[] dx = new int[]{-1, 1, 0, 0};
    private int[] dy = new int[]{0, 0, -1, 1};

    private boolean check(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    public int orangesRotting(int[][] grid) {
        Queue<Integer> queue = new ArrayDeque<>();
        int all = 0;
        int cnt = 0;
        m = grid.length;
        n = grid[0].length;
        boolean[][] v = new boolean[m][n];
        int[][] dis = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) all++;
                else if (grid[i][j] == 2) {
                    all++;
                    cnt++;
                    queue.add(i * a + j);
                    v[i][j] = true;
                    dis[i][j] = 0;
                } else {
                    v[i][j] = true;
                }
            }
        }

        int res = 0;
        while (!queue.isEmpty()) {
            Integer poll = queue.poll();
            int row = poll / a;
            int col = poll % a;
            for (int i = 0; i < 4; i++) {
                int x = row + dx[i];
                int y = col + dy[i];
                if (check(x, y) && !v[x][y]) {
                    queue.add(x * a + y);
                    cnt++;
                    dis[x][y] = dis[row][col] + 1;
                    res = Math.max(res, dis[x][y]);
                    v[x][y] = true;
                }
            }
        }
        if (all == cnt) {
            return res;
        } else {
            return -1;
        }
    }
}
