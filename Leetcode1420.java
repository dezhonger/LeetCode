package com.netease.music.leetcode;

public class Leetcode1420 {


    int mod = 10_0000_0007;

    public int numOfArrays(int n, int m, int k) {
        //前i个数，最大值是j,cost=k的方法数
        int[][][] dp = new int[n + 5][m + 5][k + 5];
        dp[0][0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int p = 0; p <= k; p++) {
                    if (p > 0) {
                        for (int last = 0; last < j; last++) {
                            dp[i][j][p] += dp[i - 1][last][p - 1];
                        }
                    }
                    for (int last = j; last <= m; last++) {
                        dp[i][last][p] += dp[i - 1][last][p];
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= m; j++) {
            ans += dp[n][j][k];
        }
        return (ans % mod);
    }
}
