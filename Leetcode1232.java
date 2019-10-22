package com.netease.music.leetcode;

import java.util.Objects;

/**
 * Created by dezhonger on 2019/10/22
 */
public class Leetcode1232 {
    public boolean checkStraightLine(int[][] coordinates) {
        int len = coordinates.length;
        for (int i = 2; i < len; i++) {
            int y = coordinates[1][1] - coordinates[0][1];
            int x = coordinates[1][0] - coordinates[0][0];

            int yy = coordinates[i][1] - coordinates[0][1];
            int xx = coordinates[i][0] - coordinates[0][0];
             if (y * xx != x * yy) {
                 return false;
             }
        }
        return true;
    }
}
