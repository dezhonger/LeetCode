package com.y2019.m12.d26;

/**
 * Created by zhangweilong on 2019/12/25
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/25
 */
public class Leetcode1254 {

    int m, n;
    int[] dx = new int[]{0, 0, -1, 1};
    int[] dy = new int[]{-1, 1, 0, 0};

    public int closedIsland(int[][] grid) {
        this.m = grid.length;
        this.n = grid[0].length;
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) dfs(grid, i, 0);
            if (grid[i][n - 1] == 0) dfs(grid, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 0) dfs(grid, 0, i);
            if (grid[m - 1][i] == 0) dfs(grid, m - 1, i);
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(int[][] g, int x, int y) {
        if (g[x][y] == 1) return;
        g[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int _x = x + dx[i];
            int _y = y + dy[i];
            if (check(_x, _y)) {
                dfs(g, _x, _y);
            }
        }
    }

    boolean check(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
}
