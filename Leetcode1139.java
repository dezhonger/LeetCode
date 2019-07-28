package com.netease.music.p20190729;

/**
 * Created by dezhonger on 2019/7/29
 */
public class Leetcode1139 {

    int[][] sum;
    int m, n;

    private int getSum(int a, int b) {
        if (a >= 0 && a < m && b >= 0 && b < n) return sum[a][b];
        return 0;
    }

    private int getSum(int a, int b, int x, int y) {
        int s1 = getSum(x, y);
        int s2 = getSum(a - 1, y);
        int s3 = getSum(x, b - 1);
        int s4 = getSum(a - 1, b - 1);
        return s1 - s2 - s3 + s4;
    }

    public int largest1BorderedSquare(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        sum = new int[m][n];
        sum[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) sum[i][0] = sum[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++) sum[0][j] = sum[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sum[i][j] = grid[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        int result = 0;
        int maxL = Math.min(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = maxL; k >= 1; k--) {
                    int rx = i + k - 1;
                    int ry = j + k - 1;
                    if (rx >= m || ry >= n) continue;

                    int s1 = getSum(i, j, rx, ry);
                    int s2 = 0;
                    if (k > 2) {
                        s2 = getSum(i + 1, j + 1, rx - 1, ry - 1);
                    }
                    int o = k == 1 ? 1 : 4 * (k - 1);
                    if (s1 - s2 == o) {
                        result = Math.max(k * k, result);
                    }

                }
            }
        }
        return result;
    }
}
