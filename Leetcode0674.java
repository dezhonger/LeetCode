package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/5/23
 */
public class Leetcode0674 {
    public int findLengthOfLCIS(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int[] dp = new int[nums.length];
        int res = 0;
        dp[0] = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) dp[i] = dp[i-1] + 1;
            else dp[i] = 1;
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
