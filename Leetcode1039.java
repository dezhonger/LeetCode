package com.netease.music.leetcode;


import java.util.Arrays;

/**
 * Created by dezhonger on 2019/5/6
 *
 * d[i][j] = max(d[i][k] +  d[k][j] +  w(i, j, k)) (i < k < j)
 * ans: dp[0][n-1]
 */
public class Leetcode1039 {
    public static void main(String[] args) {
        new Leetcode1039().minScoreTriangulation(new int[]{1, 2, 3});
        new Leetcode1039().minScoreTriangulation(new int[]{3,7,4,5});
        new Leetcode1039().minScoreTriangulation(new int[]{1,3,1,4,1,5});
    }

    public int minScoreTriangulation(int[] A) {
        int n = A.length;
        int[][] dp = new int[n][n];
        for (int i = 0; i < dp.length; i++) Arrays.fill(dp[i], Integer.MAX_VALUE );
        for (int i = 0; i < n - 1; i++) dp[i][i+1] = 0;
        for (int i = 2; i < n; i++) {
            for (int st = 0; st < n; st++) {
                int ed = st + i;
                if (ed >= n) continue;
                for (int k = st + 1; k < ed; k++) {
                    dp[st][ed] = Math.min(dp[st][ed] , dp[st][k] + dp[k][ed] + A[st] * A[ed] * A[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
}
