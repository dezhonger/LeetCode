package com.netease.music.leetcode.contest.no174;

/**
 * Created by dezhonger on 2020/2/2
 */
public class Leetcode1344 {
    int[] arr;
    int d;
    int res;
    int[] dp;

    public int maxJumps(int[] arr, int d) {
        this.arr = arr;
        this.d = d;
        this.res = 0;
        this.dp = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            int r = go(i);
            res = Math.max(res, r);
        }
        return res;
    }


    private int go(int i) {
        if (dp[i] != 0) return dp[i];
        int step = 1;
        int tmp = 0;
        int ma1 = Integer.MIN_VALUE;
        int ma2 = Integer.MIN_VALUE;
        for (int j = i + 1; j < arr.length && j <= i + d; j++) {
            ma1 = Math.max(ma1, arr[j]);
            if (arr[i] > ma1) {
                tmp = Math.max(tmp, go(j));
            } else break;

        }

        for (int j = i - 1; j >= 0 && j >= i - d; j--) {
            ma2 = Math.max(ma2, arr[j]);
            if (arr[i] > ma2) {
                tmp = Math.max(tmp, go(j));
            } else break;
        }
        dp[i] = step + tmp;
        return dp[i];
    }
}
