package com.netease.music.p20190716;

/**
 * Created by dezhonger on 2019/7/17
 */
public class Leetcode0861 {
    public int matrixScore(int[][] A) {
        int m = A.length;
        int n = A[0].length;
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < n; j++) A[i][j] = 1 - A[i][j];
            }
        }
        for (int j = 1; j < n; j++) {
            int one = 0;
            int zero = 0;
            for (int i = 0; i < m; i++) {
                if (A[i][j] == 0) zero++;
                else one++;
            }
            if (one < zero) {
                for (int i = 0; i < m; i++) {
                    A[i][j] = 1 - A[i][j];
                }
            }
        }
        int s = 0;
        for (int i = 0; i < m; i++) {
            int t = 0;
            for (int j = 0; j < n; j++) {
                t = t * 2;
                t = t + A[i][j];
            }
            s += t;
        }
        return s;
    }
}
