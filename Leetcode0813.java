//package com.dezhonger.y2019.m07.d30;

/**
 * Created by dezhonger on 2019/07/30
 *
 * @author dezhonger
 * @since 2019/07/30
 */
public class Leetcode0813 {
    public double largestSumOfAverages(int[] A, int K) {
        int n = A.length;
        double[][] dp = new double[n + 1][K + 1];
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + A[i - 1];
            dp[i][1] = 1.0 * sum[i] / i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= Math.min(K, i); j++) {
                //dp[i][j] = max(dp[i][j], dp[i-x][j-1] + sum(i-x+1, i-x+2,....i)/x )
                for (int x = j - 1;  x < i; x++) {
                    int s = sum[i] - sum[x];
                    int cnt = i - x;
                    dp[i][j] = Math.max(dp[i][j], dp[x][j - 1] + 1.0 * s / cnt);
                }
            }
        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= K; j++) {
//                System.out.printf("dp[%s][%s]=%s\n", i, j, dp[i][j]);
//            }
//            System.out.println();
//        }
        return dp[n][K];
    }
}
