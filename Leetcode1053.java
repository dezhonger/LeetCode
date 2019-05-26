package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/5/26
 * 倒着循环，找到比当前数小的最大的那个，交换
 */
public class Leetcode1053 {
    public int[] prevPermOpt1(int[] A) {
        int len = A.length;
        boolean f = true;
        for (int i = 1; i < len; i++) {
            if (A[i - 1] > A[i]) f = false;
        }
        if (f) return A;
        for (int i = len - 2; i >= 0; i--) {
            int tmp = -1;
            int index = -1;
            for (int j = i + 1; j < len; j++) {
                if (A[j] < A[i]) {
                    if (A[j] > tmp) {
                        tmp = A[j];
                        index = j;
                    }
                }
            }
            if (index != -1) {
                int t = A[i];
                A[i] = A[index];
                A[index] = t;
                return A;
            }
        }
        return A;
    }
}
