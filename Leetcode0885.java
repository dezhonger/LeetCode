package com.y2020.m01.d11;

/**
 * Created by zhangweilong on 2020/01/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/11
 */
public class Leetcode0885 {

    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        int[][] res = new int[R * C][2];
        int num = 0;
        res[num++] = new int[]{r0, c0};
        int step = 0;
        while (num < R * C) {
            step++;
            //right
            for (int i = 0; i < step; i++) {
                c0++;
                if (check(r0, c0, R, C)) {
                    res[num++] = new int[]{r0, c0};
                }
            }

            //down
            for (int i = 0; i < step; i++) {
                r0++;
                if (check(r0, c0, R, C)) {
                    res[num++] = new int[]{r0, c0};
                }
            }

            step++;
            //left
            for (int i = 0; i < step; i++) {
                c0--;
                if (check(r0, c0, R, C)) {
                    res[num++] = new int[]{r0, c0};
                }
            }

            //up
            for (int i = 0; i < step; i++) {
                r0--;
                if (check(r0, c0, R, C)) {
                    res[num++] = new int[]{r0, c0};
                }
            }
        }
        return res;
    }

    private boolean check(int r0, int c0, int r, int c) {
        return r0 >= 0 && c0 >= 0 && r0 < r && c0 < c;
    }
}
