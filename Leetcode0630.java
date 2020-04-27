package com.netease.music.leetcode;

import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by dezhonger on 2020/04/26
 */
public class Leetcode0630 {

    int[][] dp;
    int[][] courses;
    int len;
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, (o1, o2) -> {
            if (o1[1] != o2[1]) return Integer.compare(o1[1], o2[1]);
            return Integer.compare(o1[0], o2[0]);
        });
        len = courses.length;
        this.courses = courses;
        dp = new int[len][courses[len - 1][1] + 100];
        for (int i = 0; i < dp.length; i++) Arrays.fill(dp[i], -1);
        return dfs(0, 0);
    }

    private int dfs(int index, int time) {
        if (index == len) return 0;
        if (dp[index][time] != -1) return dp[index][time];
        int take = 0;
        if (time + courses[index][0] <= courses[index][1]) {
            take = 1 + dfs(index + 1, time + courses[index][0]);
        }
        int ans = Math.max(take, dfs(index + 1, time));
        dp[index][time] = ans;
        return ans;
    }
}
