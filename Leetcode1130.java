//package com.netease.music.rep2.taskman.sync.core.nos;

import java.util.Arrays;

public class Leetcode1130 {
    public int mctFromLeafValues(int[] arr) {
        int len = arr.length;
        int[][] ma = new int[len][len];
        int[][] dp = new int[len][len];
        for (int i = 0; i < len; i++) {
            ma[i][i] = arr[i];
            for (int j = i + 1; j < len; j++) {
                ma[i][j] = Math.max(ma[i][j - 1], arr[j]);
            }
        }
        for (int i = 0; i < len ;i++) Arrays.fill(dp[i], 100_0000);
        for (int i = 0; i < len; i++) dp[i][i] = 0;
        for (int k = 2; k <= len; k++) {
            for (int i = 0; i < len ;i++) {
                int j = i + k - 1;
                if (j >= len) break;
                for (int mid = i; mid < j; mid++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + ma[i][mid] * ma[mid + 1][j]);
                }
            }
        }
//        System.out.println(dp[0][len - 1]);
        return dp[0][len - 1];
    }
}
