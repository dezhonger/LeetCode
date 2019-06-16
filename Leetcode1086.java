package com.netease.music.leetcode;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/6/16
 */
public class Leetcode1086 {
    public int[][] highFive(int[][] items) {
        Arrays.sort(items, (a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return -(a[1] - b[1]);
        });

        int n = items.length;
        int[][] ret = new int[n][];
        int p = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && items[i][0] == items[j][0]) j++;

            int s = 0;
            int num = 0;
            for (int k = 0; k < 5 && k < j - i; k++) {
                s += items[k + i][1];
                num++;
            }
            ret[p++] = new int[]{items[i][0], s / num};
            i = j;
        }
        return Arrays.copyOf(ret, p);
    }
}

