package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/5/26
 */
public class Leetcode1052 {
    public static void main(String[] args) {
        new Leetcode1052().maxSatisfied(new int[]{1, 0, 1, 2, 1, 1, 7, 5}, new int[]{0, 1, 0, 1, 0, 1, 0, 1}, 3);
    }

    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int len = customers.length;
        int s = 0;
        for (int i = 0; i < len; i++) s += (grumpy[i] == 1 ? 0 : customers[i]);
        int p = 0;
        for (int i = 0; i < X - 1; i++) p += (grumpy[i] == 0 ? 0 : customers[i]);
        int mi = Integer.MIN_VALUE;
        for (int i = X - 1; i < len; i++) {
            if (grumpy[i] == 1) p += customers[i];
            if (i - X >= 0 && grumpy[i - X] == 1) p -= customers[i - X] ;
            mi = Math.max(p, mi);
        }
        return s + mi;
    }
}
