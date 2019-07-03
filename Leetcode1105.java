package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/7/4
 *
 * 动态规划 dp[i] = min(dp[i], dp[j] + （j+1, j+2...i)最高的高度,前提是这些可以放在同一行)
 */
public class Leetcode1105 {
    public int minHeightShelves(int[][] books, int shelf_width) {
        int[] dp = new int[books.length + 1];
        dp[0] = 0;
        for (int i = 1; i <= books.length; i++) {
            dp[i] = Integer.MAX_VALUE;
            int w = 0;
            int h = 0;
            for (int j = 0; j < i; j++) {
                w += books[i - j - 1][0];
                if (w <= shelf_width) {
                    h = Math.max(h, books[i - j - 1][1]);
                    dp[i] = Math.min(dp[i], dp[i - j - 1] + h);
                } else {
                    break;
                }
            }
        }
        return dp[books.length];
    }
}
