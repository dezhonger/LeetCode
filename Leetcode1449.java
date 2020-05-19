package com.netease.music.leetcode.hard;

/**
 * Created by dezhonger on 2020/05/19
 */
public class Leetcode1449 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1449().largestNumber(new int[]{
                4,3,2,5,6,7,2,5,5
        }, 9));
    }
    public String largestNumber(int[] cost, int target) {
        //dp[i]表示能组成数字的个数
        int[] dp = new int[target + 1];
        for (int i = 1; i <= target; i++) dp[i] = -1;
        for (int i = 0; i < cost.length; i++) {
            for (int j = 0; j <= target; j++) {
                if (j >= cost[i] && dp[j - cost[i]] >= 0) dp[j] =Math.max(dp[j],  dp[j - cost[i]] + 1);
            }
        }
        if (dp[target] <= 0) return "0";
        StringBuilder sb = new StringBuilder();
        int t = target;
        for (int i = cost.length - 1; i >= 0; i--) {
            while (t - cost[i] >= 0 && dp[t] == dp[t - cost[i]] + 1) {
                t -= cost[i];
                sb.append(i + 1);
            }
        }
        return sb.toString();
    }
}
