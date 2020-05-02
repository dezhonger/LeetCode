package com.netease.music.leetcode.hard;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Created by dezhonger on 2020/05/03
 */
public class Leetcode1425 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1425().constrainedSubsetSum(new int[]{10,2,-10,5,20}, 2));
        System.out.println(new Leetcode1425().constrainedSubsetSum(new int[]{-1,-2,-3}, 1));
        System.out.println(new Leetcode1425().constrainedSubsetSum(new int[]{10,-2,-10,-5,20}, 2));
    }
    public int constrainedSubsetSum(int[] nums, int k) {
        int len = nums.length;
        Deque<Integer> q = new ArrayDeque<>();
        int ans = Integer.MIN_VALUE;
        int[] dp = new int[len];
        for (int i = 0; i < len; i++) {
            int cur = nums[i];
            if (!q.isEmpty()) {
                cur = Math.max(cur, cur + dp[q.getFirst()]);
            }
            while (!q.isEmpty() && q.getFirst() < i - k + 1) q.pollFirst();
            dp[i] = cur;
            while (!q.isEmpty() && dp[q.getLast()] <= dp[i]) q.pollLast();
            q.addLast(i);
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}
