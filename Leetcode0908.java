package com.netease.music.leetcode;

import java.util.Arrays;
import java.util.OptionalInt;

/**
 * Created by dezhonger on 2019/7/11
 */
public class Leetcode0908 {
    public int smallestRangeI(int[] A, int K) {
        int max = Arrays.stream(A).max().getAsInt();
        int min = Arrays.stream(A).min().getAsInt();
        int dif = max - min;
        if (dif <= 2 * K) return 0;
        else return dif - 2 * K;
    }
}
