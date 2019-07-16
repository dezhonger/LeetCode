package com.netease.music.p20190716;

/**
 * Created by dezhonger on 2019/7/16
 */
public class Leetcode0598 {
    public int maxCount(int m, int n, int[][] ops) {
        for (int[] op : ops) {
            m = Math.min(m, op[0]);
            n = Math.min(n, op[1]);
        }
        return m * n;
    }
}
