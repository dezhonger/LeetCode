package com.y2020.m01.d29;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2020/02/29
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/02/29
 */
public class Leetcode0891 {
    public int sumSubseqWidths(int[] A) {
        int mod = 10_0000_0007;
        Arrays.sort(A);
        long res = 0;
        int[] pow = new int[A.length];
        pow[0] = 1;
        for (int i = 1; i < A.length; i++) pow[i] = pow[i - 1] * 2 % mod;
        for (int i = 0; i < A.length; i++) {
            res += 1L * pow[i] * A[i];
            res -= 1L * pow[A.length - 1 - i] * A[i];
            res %= mod;
        }
        return (int) res;
    }
}
