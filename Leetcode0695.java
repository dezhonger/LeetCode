package com.y2019.m12.d28;

/**
 * Created by zhangweilong on 2019/12/28
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/28
 */
public class Leetcode0695 {
    int res, m, n;
    int[] dx = new int[]{0, 0, -1, 1};
    int[] dy = new int[]{-1, 1, 0, 0};

    public int maxAreaOfIsland(int[][] grid) {
        res = 0;
        m = grid.length;
        n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = Math.max(dfs(grid, i, j, 0), res);
                }
            }
        }
        return res;
    }

    private boolean check(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    private int dfs(int[][] grid, int x, int y, int area) {
        grid[x][y] = -1;
        area++;
        for (int i = 0; i < 4; i++) {
            int _x = x + dx[i];
            int _y = y + dy[i];
            if (check(_x, _y) && grid[_x][_y] == 1) {
                area += dfs(grid, _x, _y, 0);
            }
        }
        return area;
    }
}
