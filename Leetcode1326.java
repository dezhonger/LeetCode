package com.dezhonger.y2020.m01.d19;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/01/20
 *
 * @author dezhonger
 * @since 2020/01/20
 */
public class Leetcode1326 {
    public int minTaps(int n, int[] ranges) {
        int[][] a = new int[ranges.length][2];
        for (int i = 0; i < ranges.length; i++) {
            a[i][0] = Math.max(0, i - ranges[i]);
            a[i][1] = Math.min(n, i + ranges[i]);
        }
        Arrays.sort(a, (o1, o2) -> {
            if (o1[0] != o2[0]) return Integer.compare(o1[0], o2[0]);
            return Integer.compare(o2[1], o1[1]);
        });

        int res = 0;
        int right = 0;
        for (int i = 0; i < a.length; ) {
            if (a[i][0] > right) return -1;

            int maRight = -1;
            int j;
            for (j = i; j < a.length && a[j][0] <= right; j++) {
                if (a[j][1] <= right) continue;
                maRight = Math.max(maRight, a[j][1]);
            }

            if (maRight != -1) {
                res++;
                right = Math.max(right, maRight);
            }
            i = j;
            if (right >= n) break;
        }
        return res;
    }
}
