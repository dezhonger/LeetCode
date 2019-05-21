package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/5/22
 */
public class Leetcode0849 {
    public int maxDistToClosest(int[] seats) {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < seats.length; i++) {
            if (seats[i] == 1) list.add(i);
        }
        int size = list.size();
        int r = Integer.MIN_VALUE;
        for (int i = 1; i < size; i++) {
            int mid = (list.get(i) + list.get(i - 1)) / 2;
            r = Math.max(r, Math.min(mid - list.get(i - 1), list.get(i) - mid));
        }
        r = Math.max(r, seats.length - 1 - list.get(size - 1));
        r = Math.max(r, list.get(0));
        return r;
    }
}
