package com.netease.music.p20200212;

/**
 * Created by dezhonger on 2020/2/12
 */
public class Leetcode0799 {
    public double champagneTower(int poured, int query_row, int query_glass) {
        query_row++;
        query_glass++;
        double[][] d = new double[query_row + 2][query_row + 2];
        d[1][1] = poured;
        for (int i = 1; i <= query_row; i++) {
            for (int j = 1; j <= i; j++) {
                if (d[i][j] > 1) {
                    double x = (d[i][j] - 1) / 2;
                    d[i + 1][j] += x;
                    d[i + 1][j + 1] += x;
                    d[i][j] = 1;
                }
            }
        }
        return d[query_row][query_glass];
    }
}
