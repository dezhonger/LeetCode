package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2020/04/25
 */
public class Leetcode0629 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0629().kInversePairs(3, 0));
        System.out.println(new Leetcode0629().kInversePairs(3, 1));
        System.out.println(new Leetcode0629().kInversePairs(3, 2));
        System.out.println(new Leetcode0629().kInversePairs(2, 1));
    }

    public int kInversePairs(int n, int k) {
        //dp[i][j]: 前i个数的逆序对为j的方案数
        //dp[i][j] = dp[i-1][j-1] + dp[i-1][j] - dp[i-1][j-i];
        int[][] dp = new int[n + 5][k + 5];
        int mod = 10_0000_0007;
        dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > (i - 1) * i / 2) dp[i][j] = 0;
                else if (j == 0) dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                    dp[i][j] %= mod;
                    if (j - i >= 0) {
                        dp[i][j] -= dp[i - 1][j - i];
                        dp[i][j] += mod;
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        return dp[n][k];
    }

    //O(n^3)
    public int kInversePairs_2(int n, int k) {
        //dp[i][j]: 前i个数的逆序对为j的方案数
        //dp[i][j] = dp[i-1][j-k] k∈(0, i-1)
        int[][] dp = new int[n + 5][k + 5];
        int mod = 10_0000_0007;
        dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > (i - 1) * i / 2) dp[i][j] = 0;
                else if (j == 0) dp[i][j] = 1;
                else {
                    for (int kk = 0; kk <= i - 1; kk++) {
                        if (j - kk < 0) break;
                        dp[i][j] += dp[i - 1][j - kk];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        return dp[n][k];
    }
}
