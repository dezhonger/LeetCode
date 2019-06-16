package com.netease.music.leetcode;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/6/16
 */
public class Leetcode1085 {
    public int sumOfDigits(int[] A) {
        Arrays.sort(A);
        int s = 0;
        for (char x : (A[0] + "").toCharArray()) {
            s += x - '0';
        }
        return 1 - s % 2;
    }
}
