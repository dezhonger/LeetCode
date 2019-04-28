package com.netease.music.leetcode.contest.no134;

/**
 * Created by dezhonger on 2019/4/28
 */
public class Leetcode1035 {
    public int maxUncrossedLines(int[] A, int[] B) {
        int[][] dp = new int[A.length + 2][B.length + 2];
        for (int i = 1; i <= A.length; i++) {
            for (int j = 1; j <= B.length; j++) {
                int x = A[i - 1];
                int y = B[j - 1];
                if (x == y) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[A.length][B.length];
    }
}
