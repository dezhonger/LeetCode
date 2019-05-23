package com.netease.music.leetcode;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/5/23
 */
public class Leetcode0945 {

    public int minIncrementForUnique(int[] A) {
        if (A == null || A.length == 0) return 0;
        int len = A.length;
        Arrays.sort(A);
        int res = 0;
        int mi = A[0];
        for (int i = 0; i < len; i++) {

            if (mi < A[i]) mi = A[i];
            int tmp = mi - A[i];
            res += tmp;
            mi++;
        }
        return res;
    }
}
