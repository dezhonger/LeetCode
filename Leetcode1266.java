package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/11/24
 */
public class Leetcode1266 {

    int dis(int x1, int y1, int x2, int y2) {
        int a = Math.abs(x1 - x2);
        int b = Math.abs(y1 - y2);
        return Math.max(a, b);
    }

    public int minTimeToVisitAllPoints(int[][] points) {
        int res = 0;
        for (int i = 1; i < points.length; i++) {
            res += dis(points[i - 1][0], points[i - 1][1], points[i][0], points[i][1]);
        }
        return res;
    }

}
