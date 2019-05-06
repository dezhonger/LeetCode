package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/5/6
 */
public class Leetcode1037 {
    public boolean isBoomerang(int[][] points) {
        if (points[0][0] == points[1][0] && points[0][1] == points[1][1]) return false;
        if (points[0][0] == points[2][0] && points[0][1] == points[2][1]) return false;
        if (points[1][0] == points[2][0] && points[1][1] == points[2][1]) return false;
        int a = points[1][1] - points[0][1];
        int b = points[1][0] - points[0][0];
        int c = points[2][1] - points[0][1];
        int d = points[2][0] - points[0][0];
        return a * d != b * c;
    }
}
