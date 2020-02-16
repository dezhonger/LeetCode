package com.netease.music.p20200216;

/**
 * Created by dezhonger on 2020/2/16
 */
public class Leetcode1351 {
    public int countNegatives(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int x = m - 1;
        int y = 0;
        int res = 0;
        while (x >= 0) {
            while (y < n && grid[x][y] >= 0) y++;
            res += n - y;
            x--;
        }
        return res;
    }
}
