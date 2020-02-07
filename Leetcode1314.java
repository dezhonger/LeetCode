package com.dezhonger.y2020.m02.d07;

/**
 * Created by dezhonger on 2020/02/07
 *
 * @author dezhonger
 * @since 2020/02/07
 */
public class Leetcode1314 {

    int[][] s;
    int m, n;


    public int[][] matrixBlockSum(int[][] mat, int K) {
        this.m = mat.length;
        this.n = mat[0].length;
        s = new int[m + 1][n + 1];


        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int cur = mat[i - 1][j - 1];
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + cur;
            }
        }

        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = Math.max(0, i - K);
                int c1 = Math.max(0, j - K);
                int r2 = Math.min(m - 1, i + K);
                int c2 = Math.min(n - 1, j + K);
                r1++;r2++;c1++;c2++;
                res[i][j] = s[r2][c2] - s[r2][c1 - 1] - s[r1 - 1][c2] + s[r1 - 1][c1 - 1];
            }
        }
        return res;
    }
}
