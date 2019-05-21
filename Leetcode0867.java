package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/5/22
 */
public class Leetcode0867 {
    public int[][] transpose(int[][] A) {
        int m = A.length;
        int n = A[0].length;
        int[][] r = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                r[i][j] = A[j][i];
            }
        }
        return r;
    }
}
