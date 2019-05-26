package com.netease.music.leetcode;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/5/26
 */
public class Leetcode1051 {
    public int heightChecker(int[] heights) {
        int[] a = new int[heights.length];
        System.arraycopy(heights, 0, a, 0, heights.length);
        Arrays.sort(heights);
        int r = 0;
        for (int i = 0; i < heights.length;i ++) {
            if (a[i] != heights[i]) r++;
        }
        return r;
    }
}
