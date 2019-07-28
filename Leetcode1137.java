package com.netease.music.p20190729;

/**
 * Created by dezhonger on 2019/7/29
 */
public class Leetcode1137 {
    public int tribonacci(int n) {
        int[] t = new int[38];
        t[1] = t[2] = 1;
        for (int i = 3; i < t.length; i++) t[i] = t[i - 1] + t[i - 2] + t[i - 3];
        return t[n];

    }
}
