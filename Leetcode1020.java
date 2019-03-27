package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/3/26
 */
public class Leetcode1020 {
    public static void main(String[] args) {
//        System.out.println(new Leetcode1020().canThreePartsEqualSum(new int[]{0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1}));
//        System.out.println(new Leetcode1020().canThreePartsEqualSum(new int[]{0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1}));
//        System.out.println(new Leetcode1020().canThreePartsEqualSum(new int[]{3, 3, 6, 5, -2, 2, 5, 1, -9, 4}));
        System.out.println(new Leetcode1020().canThreePartsEqualSum(new int[]{18,12,-18,18,-19,-1,10,10}));
    }

    public boolean canThreePartsEqualSum(int[] A) {
        int s = 0;
        for (int x : A) s += x;
        if (s % 3 != 0) return false;
        int t = 0;
        int c = 0;
        for (int i = 0; i < A.length; i++) {
            t += A[i];
            if (t == s / 3) {
                c++;
                if (c == 2) {
                    return true;
                }
                t = 0;
            }
        }
        return false;
    }
}
