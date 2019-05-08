package com.dezhonger.y2019.m05;

/**
 * Created by dezhonger on 2019/05/08
 *
 * @author dezhonger
 * @since 2019/05/08
 */
public class Leetcode0832 {
    public int[][] flipAndInvertImage(int[][] A) {
        int m = A.length;
        int n = A[0].length;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) A[i][j] = 1 - A[i][j];
        for (int i = 0; i < m; i++) {
            for (int j = 0, k = n - 1; j < k; j++, k--) {
                int x = A[i][j];
                A[i][j] = A[i][k];
                A[i][k] = x;

            }
        }
        return A;
    }
}
