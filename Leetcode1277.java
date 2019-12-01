package com.y2019.m12.d01;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2019/12/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/01
 */
public class Leetcode1277 {

    public static void main(String[] args) {
        Leetcode1277 sol = new Leetcode1277();
        sol.countSquares(new int[][]{
                {0, 1, 1, 1},
                {1, 1, 1, 1},
                {0, 1, 1, 1},
        });

        sol.countSquares(new int[][]{
                {0, 0, 0},
                {0, 1, 0},
                {0, 1, 0},
                {1, 1, 1},
                {1, 1, 0},
        });
    }

    public int countSquares(int[][] matrix) {
        int res = 0;
        int r = matrix.length;
        int c = matrix[0].length;

        int[][] a = new int[r][c];
        int[][] b = new int[r][c];
        int[][] f = new int[r][c];

        //（i, j）向右有连续多少个1
        for (int i = 0; i < r; i++) {
            for (int j = c - 1; j >= 0; j--) {
                if (j == c - 1) a[i][j] = matrix[i][j];
                else a[i][j] = matrix[i][j] == 0 ? 0 : a[i][j + 1] + 1;
            }
        }

        //(i, j)向下有多少个连续的1
        for (int j = 0; j < c; j++) {
            for (int i = r - 1; i >= 0; i--) {
                if (i == r - 1) b[i][j] = matrix[i][j];
                else b[i][j] = matrix[i][j] == 0 ? 0 : b[i + 1][j] + 1;
            }
        }

        //(i, j)为左上角最大正方形的边长
        for (int i = r - 1; i >= 0; i--) {
            for (int j = c - 1; j >= 0; j--) {
                if (i == r - 1 || j == c - 1) f[i][j] = matrix[i][j];
                else {
                    if (matrix[i][j] == 0) f[i][j] = 0;
                    else f[i][j] = Math.min(Math.min(a[i][j], b[i][j]), f[i + 1][j + 1] + 1);
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res += f[i][j];
            }
        }
        return res;
    }
}
