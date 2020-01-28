package com.dezhonger.y2020.m01.d28;

/**
 * Created by dezhonger on 2020/01/29
 *
 * @author dezhonger
 * @since 2020/01/29
 */
public class Leetcode0801 {
    public int minSwap(int[] A, int[] B) {
        //f[i] 不交换第i位的最小交换次数
        //g[i] 交换第i位的最小交换次数

        int ma = 1000_0000;

        int len = A.length;
        int[] f = new int[len];
        int[] g = new int[len];
        f[0] = 0;
        g[0] = 1;
        for (int i = 1; i < len; i++) {
            f[i] = g[i] = ma;

            if (A[i] > A[i - 1] && B[i] > B[i-1]) {
                //都不交换
                f[i] = Math.min(f[i], f[i - 1]);
                //都交换
                g[i] = Math.min(g[i], g[i - 1] + 1);
            }

            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                //第i位不交换
                f[i] = Math.min(f[i], g[i - 1]);
                //第i位交换
                g[i] = Math.min(f[i - 1] + 1, g[i]);
            }

        }

        int res = Math.min(f[len - 1], g[len - 1]);
        return res;
    }
}
