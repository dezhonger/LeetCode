package com.netease.music.leetcode;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/3/28
 */
public class Leetcode1072 {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int res = 1;
        for (int i = 0; i < n; i++) {
            int c = 1;
            for (int j = i + 1; j < n; j++) {
                if (Arrays.equals(matrix[i], matrix[j])) c++;
                else {
                    boolean f = true;
                    for (int k = 0; k < m; k++) {
                        if (matrix[i][k] + matrix[j][k] != 1) {
                            f = false;
                            break;
                        }
                    }
                    if (f) c++;
                }
            }
            res = Math.max(res, c);
        }
        return res;
    }
}
