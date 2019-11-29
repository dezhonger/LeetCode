package com.dezhonger.y2019.m11.d30;

/**
 * Created by dezhonger on 2019/11/29
 *
 * @author dezhonger
 * @since 2019/11/29
 */
public class Leetcode980_dfs {
    public static void main(String[] args) {
        int[][] grid = new int[][]{
                {1, 2},
                {0, 0},
        };

        int[][] grid2 = new int[][]{
                {1, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 2, -1},
        };
        Leetcode980_dfs sol = new Leetcode980_dfs();
        System.out.println(sol.uniquePathsIII(grid));
        System.out.println(sol.uniquePathsIII(grid2));
    }

    int ex = 0, ey = 0;
    int sx = 0, sy = 0;
    int res = 0, r = 0, c = 0;
    int[] dx = new int[]{0, 1, 0, -1};
    int[] dy = new int[]{1, 0, -1, 0};

    public int uniquePathsIII(int[][] grid) {
        res = 0;
        r = grid.length;
        c = grid[0].length;

        int cnt = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                } else if (grid[i][j] == 2) {
                    ex = i;
                    ey = j;
                    cnt++;
                } else if (grid[i][j] == 0) {
                    cnt++;
                }
            }
        }

        grid[sx][sy] = -2;
        return dfs(cnt, sx, sy, grid);

    }

    private int dfs(int n, int x, int y, int[][] grid) {
        //-1 obstacles, -2: 走过了
        if (x == ex && y == ey) {
            //n = 0：走完了所有的格子
            return n == 0 ? 1 : 0;
        }

        int res = 0;
        for (int i = 0; i < 4; i++) {
            int _x = x + dx[i];
            int _y = y + dy[i];

            if (_x < 0 || _y < 0 || _x >= r || _y >= c || grid[_x][_y] == -1 || grid[_x][_y] == -2) {
                continue;
            }
            //-2表示已经走过了
            grid[_x][_y] = -2;
            res += dfs(n - 1, _x, _y, grid);
            grid[_x][_y] = 0;
        }
        return res;
    }




}
