package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/3/26
 */
public class Leetcode1021 {
    public int maxScoreSightseeingPair(int[] A) {
        int len = A.length;
        int max = Integer.MIN_VALUE;
        int res = Integer.MIN_VALUE;
        for (int i = len - 2; i >= 0; i--) {
            max = Math.max(max, A[i + 1] - (i + 1));
            res = Math.max(res, A[i] + i + max);
        }
        return res;
    }
}
