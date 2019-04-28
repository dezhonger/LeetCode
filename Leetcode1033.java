package com.netease.music.leetcode.contest.no134;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/4/28
 */
public class Leetcode1033 {

    public int[] numMovesStones(int a, int b, int c) {
        int[] x = new int[]{a, b, c};
        Arrays.sort(x);
        a = x[0];
        b = x[1];
        c = x[2];

        int mi = Integer.MAX_VALUE;
        if (a + 1 == b && b + 1 == c) mi = Math.min(mi, 0);
        else if (a + 1 == b || b + 1 == c) mi = Math.min(mi, 1);
        else if (a + 2 == b || b + 2 == c) mi = Math.min(mi, 1);
        else mi = Math.min(mi, 2);

        int ma = Integer.MIN_VALUE;

        if (a + 1 == b && b + 1 == c) ma = Math.max(ma, 0);
        else if (a + 1 == b) ma = Math.max(ma, c - b - 1);
        else if (b + 1 == c) ma = Math.max(ma, b - a - 1);
        else ma = Math.max(ma, b - a - 1 + c - b - 1);

        return new int[]{mi, ma};

    }
}
