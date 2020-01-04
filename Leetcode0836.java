package com.y2020.m01.d04;

/**
 * Created by zhangweilong on 2020/01/04
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/04
 */
public class Leetcode0836 {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int[] p1 = new int[]{rec1[0], rec1[1]};
        int[] p2 = new int[]{rec1[2], rec1[3]};

        int[] p3 = new int[]{rec2[0], rec2[1]};
        int[] p4 = new int[]{rec2[2], rec2[3]};


        //https://leetcode.com/problems/rectangle-overlap/discuss/133175/C%2B%2B-Solution-with-easy-explanation
        //x1 < x4, x3 < x2
        //y1 < y4, y3 < y2
        return p1[0] < p4[0] && p3[0] < p2[0] && p1[1] < p4[1] && p3[1] < p2[1];
    }
}
