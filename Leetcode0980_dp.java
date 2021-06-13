package com.dezhonger.y2019.m11.d30;

/**
 * Created by dezhonger on 2019/11/29
 *
 * @author dezhonger
 * @since 2019/11/29
 */
public class Leetcode980_dp {

    int res = 0, r = 0, c = 0;
    int[] dx = new int[]{0, 1, 0, -1};
    int[] dy = new int[]{1, 0, -1, 0};
    int ex = 0, ey = 0;
    int sx = 0, sy = 0;
    int[][] dp;
    boolean[][] v;

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
        Leetcode980_dp sol = new Leetcode980_dp();
        System.out.println(sol.uniquePathsIII(grid));
        System.out.println(sol.uniquePathsIII(grid2));
    }

    public int uniquePathsIII(int[][] grid) {
        //dp[x][y][state] 当前在(x, y)，其中还需要访问的节点为state的路径数
        //x和y通过hash压缩为一维, state使用bit表示
        //答案为dp[endx][endy][0]， 也就是当前在终点处所有点都已经访问完的方法数
        res = 0;
        r = grid.length;
        c = grid[0].length;

        int bit = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                } else if (grid[i][j] == 2) {
                    ex = i;
                    ey = j;
                    bit |= bit(hash(i, j));
                } else if (grid[i][j] == 0) {
                    bit |= bit(hash(i, j));
                }
            }
        }
        dp = new int[r * c][1 << 20];
        v = new boolean[r * c][1 << 20];
        //需要求出 dp[hash(sx, sy)][bit]

        //记忆化搜索
        grid[sx][sy] = -1;
        return dfs(bit, sx, sy, grid);
    }

    private int dfs(int state, int x, int y, int[][] grid) {
        if (v[hash(x, y)][state]) {
            return dp[hash(x, y)][state];
        }
        if (x == ex && y == ey) {
            return state == 0 ? 1 : 0;
        }
        int res = 0;
        for (int i = 0; i < 4; i++) {
            int _x = x + dx[i];
            int _y = y + dy[i];
            if (_x < 0 || _y < 0 || _x >= r || _y >= c || grid[_x][_y] == -1) {
                continue;
            }
            //改点还未被访问
            int t = bit(hash(_x, _y));
            if ((state & t) > 0) {
                res += dfs(state ^ t, _x, _y, grid);
            }
        }
        dp[hash(x, y)][state] = res;
        v[hash(x, y)][state] = true;
        return res;
    }


    private int hash(int i, int j) {
        return i * c + j;
    }

    private int bit(int x) {
        return 1 << x;
    }
}
