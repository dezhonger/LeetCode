package com.netease.music.leetcode.contest.no137;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/5/19
 */
public class Leetcode1049 {
    public int lastStoneWeightII(int[] stones) {
        int s = 0;
        int sum = Arrays.stream(stones).sum();
        boolean[] dp = new boolean[sum + 1];
        dp[0] = true;
        for (int x : stones) {
            for (int j = sum; j >= x; j--) {
                dp[j] |= dp[j - x];
            }
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i <= sum; i++) {
            if (dp[i]) res = Math.min(res, Math.abs(sum - i - i));
        }
        return res;
    }
}
