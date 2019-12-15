package com.y2019.m12.d15;

/**
 * Created by zhangweilong on 2019/12/15
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/15
 */
public class Leetcode1292 {
    int m, n;
    int[][] s;

    public int maxSideLength(int[][] mat, int threshold) {
        m = mat.length;
        n = mat[0].length;
        s = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    s[i][j] = mat[i][j];
                } else if (i == 0) {
                    s[i][j] = s[i][j - 1] + mat[i][j];
                } else if (j == 0) {
                    s[i][j] = s[i - 1][j] + mat[i][j];
                } else {
                    s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i][j];
                }
            }
        }

        int l = 1;
        int r = Math.min(m, n);
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid, s, threshold)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private int getValue(int x, int y) {
        if (x < 0 || y < 0) return 0;
        return s[x][y];
    }

    private boolean check(int mid, int[][] s, int threshold) {
        for (int i = 0; i < m; i++) {
            int x = i + mid - 1;
            if (x >= m) break;
            for (int j = 0; j < n; j++) {
                int y = j + mid - 1;
                if (y >= n) break;
                int sum0 = getValue(x, y);
                int sum1 = getValue(x, j - 1);
                int sum2 = getValue(i - 1, y);
                int sum3 = getValue(i - 1, j - 1);
                int sum = sum0 - sum1 - sum2 + sum3;
                if (sum <= threshold) return true;
            }
        }
        return false;
    }
}
