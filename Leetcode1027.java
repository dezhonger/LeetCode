package com.netease.music.leetcode.contest.no132;

/**
 * Created by dezhonger on 2019/4/14
 */
public class Leetcode1027 {

    public int longestArithSeqLength(int[] A) {
        int ans = 2;
        int n = A.length;
        int diff = 10000;
        int[][] dp = new int[10010][20010];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int d = A[i] - A[j];
                int ddiff = d + diff;
                if (dp[j][ddiff] == 0) {
                    dp[i][ddiff] = 2;
                } else {
                    dp[i][ddiff] = dp[j][ddiff] +1;
                }
                ans = Math.max(ans, dp[i][ddiff]);
            }
        }
        return ans;
    }
}
