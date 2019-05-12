package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/5/12
 */
public class Leetcode1043 {
    public int maxSumAfterPartitioning(int[] A, int K) {

        int len = A.length;
        int[][] ma = new int[len + 1][len + 1];
        for (int i = 0; i < len; i++) {
            int tmp = A[i];
            for (int j = i; j < len; j++) {
                tmp = Math.max(tmp, A[j]);
                ma[i + 1][j + 1] = tmp;
            }
        }
        int[] dp = new int[len + 1];
        for (int i = 1; i <= len; i++) {
            int cur = A[i - 1];
            dp[i] = dp[i - 1] + cur;
            for (int j = 1; j <= K && i - j >= 0; j++) {
                dp[i] = Math.max(dp[i], dp[i - j] + ma[i - j + 1][i] * j);
//                if (i ==4 && dp[i] == 60) System.out.println(j);
            }
            if (i <= K) {
                dp[i] = Math.max(dp[i], ma[1][i] * i);
            }
        }
        return dp[len];
    }
}
