package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/4/1
 *
 * 题意：交换A和B的部分值，让A数组或B数组值相等
 *
 * 分析：如果答案存在，这个数一定是A或B中的众数，且这个数的个数 >= A.length / 2
 */
public class Leetcode1007 {

    public static void main(String[] args) {
        Leetcode1007 code = new Leetcode1007();
        System.out.println(code.minDominoRotations(new int[]{2, 1, 2, 4, 2, 2}, new int[]{5,2,6,2,3,2}));
        System.out.println(code.minDominoRotations(new int[]{3,5,1,2,3}, new int[]{3,6,3,3,4}));
    }

    public int minDominoRotations(int[] A, int[] B) {
        int z1 = f(A);
        int z2 = f(B);
        int r1 = check(A, B, z1);
        if (r1 != Integer.MAX_VALUE) {
            r1 = Math.min(r1, A.length - r1);
        }

        int r2 = check(A, B, z2);
        if (r2 != Integer.MAX_VALUE) {
            r2 = Math.min(r2, A.length - r2);
        }

        int r3 = check(B, A, z1);
        if (r3 != Integer.MAX_VALUE) {
            r3 = Math.min(r3, A.length - r3);
        }

        int r4 = check(B, A, z2);
        if (r4 != Integer.MAX_VALUE) {
            r4 = Math.min(r4, A.length - r4);
        }

        int rr1 = Math.min(r1, r2);
        int rr2 = Math.min(r3, r4);
        int r = Math.min(rr1, rr2);
        if (r == Integer.MAX_VALUE) r = -1;
        return r;
    }

    private int check(int[] a, int[] b, int z) {
        int c = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == z) continue;
            else if (b[i] == z) c++;
            else return Integer.MAX_VALUE;
        }
        return c;
    }

    private int f(int[] a) {
        int r = -1;
        int c = 1;
        for (int x : a ) {
            if (x == r) c++;
            else {
                c--;
                if (c == 0) {
                    c =1;
                    r = x;
                }
            }
        }
        return r;
    }
}
