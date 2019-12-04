package com.dezhonger.le;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/12/04
 *
 * @author dezhonger
 * @since 2019/12/04
 */
public class Leetcode1219 {
    int res = -1;
    int m, n;
    int[] dx = new int[]{-1, 0, 1, 0};
    int[] dy = new int[]{0, 1, 0, -1};

    public int getMaximumGold(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int tmp = grid[i][j];
                    grid[i][j] = 0;
                    dfs(i, j, grid, tmp);
                    grid[i][j] = tmp;

                }
            }
        }
        return res;
    }

    private void dfs(int i, int j, int[][] grid, int sum) {
        res = Math.max(res, sum);
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || y < 0 || x >= m || y >= n) {
                continue;
            }
            if (grid[x][y] > 0) {
                int tmp = grid[x][y];
                grid[x][y] = 0;
                dfs(x, y, grid, sum + tmp);
                grid[x][y] = tmp;
            }
        }
    }
}
