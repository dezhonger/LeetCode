package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/4/6
 * <p>
 * dp[i]:完成第1天到第i天的最小话费
 * if 第i天不需要旅行 dp[i] = dp[i-1]
 * else dp[i] = min(dp[i-1] + costs[0], dp[i-7] + costs[1], dp[i-30] + costs[2])
 * <p>
 * 举例:dp[i-7] + costs[1],表示完成前i-7的后，在第i-6天买一张周票完成 i-6,i-5,i-4,i-3,i-2,i-1,i的旅行
 */
public class Leetcode0983 {
    public static void main(String[] args) {
//        System.out.println(new Leetcode0983().mincostTickets(new int[]{1,4,6,7,8,20}, new int[]{7,2,15}));
        System.out.println(new Leetcode0983().mincostTickets(new int[]{1,4,6,7,8,20}, new int[]{2,7,15}));
//        System.out.println(new Leetcode0983().mincostTickets(new int[]{1,2,3,4,5,6,7,8,9,10,30,31}, new int[]{2,7,15}));
    }

    public int mincostTickets(int[] days, int[] costs) {
        boolean[] v = new boolean[366];
        for (int x : days) v[x] = true;
        int[] dp = new int[366];
        for (int i = 1; i <= 365; i++) {
            if (v[i]) {
                int mi = dp[i - 1] + costs[0];
                if (i >= 7) {
                    mi = Math.min(mi, dp[i - 7] + costs[1]);
                } else {
                    mi = Math.min(costs[1], mi);
                }
                if (i >= 30) {
                    mi = Math.min(mi, dp[i - 30] + costs[2]);
                } else {
                    mi = Math.min(costs[2], mi);
                }
                dp[i] = mi;
            }
            else dp[i] = dp[i - 1];
            System.out.println(i+" "+dp[i]);

        }
        return dp[365];
    }

}
