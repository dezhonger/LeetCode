package com.y2020.m01.d02;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by zhangweilong on 2020/01/02
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/02
 */
public class Leetcode0057 {
    public static void main(String[] args) {
        Leetcode0057 sol = new Leetcode0057();
        System.out.println(Arrays.deepToString(sol.insert(new int[][]{
                {1, 3},
                {6, 9},
        }, new int[]{2, 5})));
    }
    public int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals == null || intervals.length == 0) return new int[][]{newInterval};
        List<int[]> res = new LinkedList<>();
        int i = 0;
        while (i < intervals.length && intervals[i][1] < newInterval[0]) {
            res.add(intervals[i]);
            i++;
        }
        int left = newInterval[0];
        int right = newInterval[1];
        while (i < intervals.length && intervals[i][0] <= newInterval[1]) {
            left = Math.min(left, intervals[i][0]);
            right = Math.max(right, intervals[i][1]);
            i++;
        }
        res.add(new int[]{left, right});
        while (i < intervals.length) {
            res.add(intervals[i++]);
        }
        int[][] r = new int[res.size()][2];
        for (int k = 0; k < res.size(); k++) {
            r[k] = res.get(k);
        }
        return r;
    }
}
