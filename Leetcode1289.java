package com.y2019.m12.d15;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2019/12/15
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/15
 */
public class Leetcode1289 {
    public int minFallingPathSum(int[][] arr) {
        int m = arr.length;
        int[][] dp = new int[m][m];
        for (int i = 0; i < m; i++) dp[0][i] = arr[0][i];
        int res = Integer.MAX_VALUE;
        for (int i = 1; i < m; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    if (j == k) continue;
                    dp[i][j] =  Math.min(dp[i][j], dp[i-1][k] + arr[i][j]);
                }
            }
            if (i == m - 1) {
                for (int j = 0; j < m; j++) res = Math.min(res, dp[i][j]);
            }
        }
        return res;
    }
}
