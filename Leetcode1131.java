package com.dezhonger.y2019.m07.d21;

/**
 * Created by dezhonger on 2019/07/21
 *
 * @author dezhonger
 * @since 2019/07/21
 */
public class Leetcode1131 {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int[] op1 = new int[]{-1, 1};
        int[] op2 = new int[]{-1, 1};
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int min = Integer.MAX_VALUE;
                int max = Integer.MIN_VALUE;
                for (int k = 0; k < arr1.length; k++) {
                    int cur = arr1[k] * op1[i] + arr2[k] * op2[j] + k;
                    min = Math.min(min, cur);
                    max = Math.max(max, cur);
                }
                res = Math.max(res, max - min);
            }
        }
        return res;
    }
}
