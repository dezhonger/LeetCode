package com.dezhonger.y2020.m01.d21;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2020/01/21
 *
 * @author dezhonger
 * @since 2020/01/21
 */
public class Leetcode0823 {

    public int numFactoredBinaryTrees(int[] A) {
        Arrays.sort(A);
        long mod = 10_0000_0007;
        long[] res = new long[A.length];
        for (int i = 0; i < res.length; i++) {
            res[i] = 1;
        }
        long result = 1L;
        for (int i = 1; i < A.length; i++) {
            int l = 0, r = i - 1;
            while (l <= r) {
                if (A[l] * A[r] < A[i]) l++;
                else if (A[l] * A[r] > A[i]) r--;
                else {
                    if (l == r) {
                        res[i] = res[i] + res[l] * res[r];
                        break;
                    } else {
                        res[i] = res[i] + 2 * res[l] * res[r];
                        r--;
                        l++;
                    }

                }
                res[i] %= mod;
            }
            result = result + res[i];
        }
        return (int) (result % mod);
    }
}
