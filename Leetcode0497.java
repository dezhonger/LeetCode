package com.dezhonger.y2020.m01.d26;

import java.util.Random;
import java.util.TreeMap;

/**
 * Created by dezhonger on 2020/01/26
 *
 * @author dezhonger
 * @since 2020/01/26
 */
public class Leetcode0497 {
    int[][] arr;
    TreeMap<Integer, Integer> map;
    int sum;
    Random random;

    public Leetcode0497(int[][] rects) {
        this.arr = rects;
        map = new TreeMap<>();
        sum = 0;
        random = new Random();

        for (int i = 0; i < rects.length; i++) {
            int[] rect = rects[i];
            //矩形内整点的个数
            sum += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            map.put(sum, i);
        }
    }

    public int[] pick() {
        int c = random.nextInt(sum + 1);
        //>=c的最小值
        int in = map.ceilingKey(c);
        return pickInRect(arr[map.get(in)]);
    }

    private int[] pickInRect(int[] rect) {
        int left = rect[0], right = rect[2], bot = rect[1], top = rect[3];
        return new int[]{left + random.nextInt(right - left + 1), bot + random.nextInt(top - bot + 1)};
    }
}
