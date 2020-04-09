package com.netease.music.leetcode;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by dezhonger on 2020/4/10
 */
public class Leetcode0757 {

    public int intersectionSizeTwo(int[][] intervals) {
        int len = intervals.length;
        Arrays.sort(intervals, Comparator.comparingInt(o -> o[1]));

        int firstLarge = -1;
        int secondLarge = -1;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            int[] cur = intervals[i];
            int cnt = intersectionNumber(firstLarge, secondLarge, cur[0], cur[1]);
            if (cnt == 0) {
                ans += 2;
                firstLarge = cur[1];
                secondLarge = firstLarge - 1;
            } else if (cnt == 1) {
                secondLarge = firstLarge;
                firstLarge = cur[1];
                ans++;
            }
        }
        return ans;
    }

    private int intersectionNumber(int x, int y, int a, int b) {
        int ans = 0;
        if (x >= a && x <= b) ans++;
        if (y >= a && y <= b) ans++;
        return ans;
    }

}

