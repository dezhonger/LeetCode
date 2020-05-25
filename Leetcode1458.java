package com.y2020.m05.d25;

/**
 * Created by zhangweilong on 2020/05/25
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/05/25
 */
public class Leetcode1458 {

    public int maxDotProduct(int[] nums1, int[] nums2) {
        int ans = Integer.MIN_VALUE;
        int[][] dp = new int[nums1.length + 1][nums2.length + 1];
        for (int i = 0; i <= nums1.length; i++) {
            for (int j = 0; j <= nums2.length; j++) {
                dp[i][j] = Integer.MIN_VALUE / 1000;
            }
        }
        for (int i = 1; i <= nums1.length; i++) {
            for (int j = 1; j <= nums2.length; j++) {
                int x = nums1[i - 1];
                int y = nums2[j - 1];
                dp[i][j] = x * y;
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + x * y);
                if (i > 1) dp[i][j] = Math.max(dp[i - 1][j], dp[i][j]);
                if (j > 1) dp[i][j] = Math.max(dp[i][j - 1], dp[i][j]);
                ans = Math.max(ans, dp[i][j]);
            }
        }
        return ans;
    }
}
