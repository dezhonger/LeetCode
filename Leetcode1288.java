package com.y2019.m12.d15;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by zhangweilong on 2019/12/15
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/15
 */
public class Leetcode1288 {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] != o2[0]) return Integer.compare(o1[0], o2[0]);
                return Integer.compare(o2[1], o1[1]);
            }
        });
        int num = 0;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][1] <= right) num++;
            else {
                right = intervals[i][1];
            }
        }
        return intervals.length - num;
    }
}
