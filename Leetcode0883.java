package com.y2020.m01.d03;

/**
 * Created by zhangweilong on 2020/01/03
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/03
 */
public class Leetcode0883 {
    public int projectionArea(int[][] grid) {
        int res = 0, n = grid.length;
        for (int i = 0; i < n; ++i) {
            int x = 0, y = 0;
            for (int j = 0; j < n; ++j) {
                x = Math.max(x, grid[i][j]);
                y = Math.max(y, grid[j][i]);
                if (grid[i][j] > 0) ++res;
            }
            res += x + y;
        }
        return res;
    }

}
