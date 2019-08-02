package com.y2019.m08.d02;

/**
 * Created by zhangweilong on 2019/08/02
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/08/02
 */
public class Leetcode1143 {
    public int longestCommonSubsequence(String text1, String text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else {
                    char c1 = text1.charAt(i - 1);
                    char c2 = text2.charAt(j - 1);
                    if (c1 == c2) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[len1][len2];
    }
}
