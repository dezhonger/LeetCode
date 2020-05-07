package com.netease.music.leetcode.hard;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2020/05/07
 */
public class Leetcode0391 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0391().isRectangleCover(new int[][]{
                {1, 1, 3, 3},
                {3, 1, 4, 2},
                {3, 2, 4, 4},
                {1, 3, 2, 4},
                {2, 3, 3, 4},
        }));

//        System.out.println(new Leetcode0391().isRectangleCover(new int[][]{
//                {1, 1, 2, 3},
//                {1, 3, 2, 4},
//                {3, 1, 4, 2},
//                {3, 2, 4, 4},
//        }));
    }

    public boolean isRectangleCover(int[][] rectangles) {
        int x1, y1, x2, y2;
        x1 = y1 = Integer.MAX_VALUE;
        x2 = y2 = Integer.MIN_VALUE;
        int s = 0;
        Set<String> set = new HashSet<>();
        for (int[] x : rectangles) {
            x1 = Math.min(x1, x[0]);
            y1 = Math.min(y1, x[1]);
            x2 = Math.max(x2, x[2]);
            y2 = Math.max(y2, x[3]);
            s += (x[2] - x[0]) * (x[3] - x[1]);
            String[] points = new String[]{
                    x[0] + " " + x[1],
                    x[0] + " " + x[3],
                    x[2] + " " + x[1],
                    x[2] + " " + x[3],
            };
            for (String point : points) {
                if (!set.add(point)) set.remove(point);
            }
        }
        String[] corner = new String[]{
                x1 + " " + y1,
                x1 + " " + y2,
                x2 + " " + y1,
                x2 + " " + y2,
        };
        if (set.size() != 4) return false;
        for (String x : corner) if(!set.contains(x)) return false;
        int area = (x2 - x1) * (y2 - y1);
        return area == s;
    }

}
