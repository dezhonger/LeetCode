package com.netease.music.p20200205;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/2/5
 */
public class Leetcode1223 {
    public int dieSimulator(int n, int[] rollMax) {
        int mod = 10_0000_0007;
        int[][][] dp = new int[n + 1][20][20];
        for (int j = 1; j <= 6; j++) dp[1][j][1] = 1;
        int[] sum = new int[7];
        Arrays.fill(sum, 1);
        int s = 6;
        for (int i = 2; i <= n; i++) {
            int[] sum2 = new int[7];
            int s2 = 0;
            for (int j = 1; j <= 6; j++) {
                for (int k = 1; k <= rollMax[j - 1]; k++) {
                    if (k == 1) {
                        dp[i][j][k] = (s - sum[j] + mod) % mod;
                    } else {
                        dp[i][j][k] += dp[i - 1][j][k - 1];
                    }
                    sum2[j] += dp[i][j][k];
                    sum2[j] %= mod;
                }
                s2 += sum2[j];
                s2 %= mod;
            }
            sum = sum2;
            s = s2 % mod;
        }
        return s % mod;
    }
}
