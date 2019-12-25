package com.y2019.m12.d26;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

/**
 * Created by zhangweilong on 2019/12/25
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/25
 */
public class Leetcode0846 {
    public boolean isNStraightHand(int[] hand, int W) {
        int len = hand.length;
        if (len % W != 0) return false;
        Map<Integer, Integer> map = new HashMap<>();
        Set<Integer> set = new TreeSet<>();
        for (int x : hand) {
            map.put(x, map.getOrDefault(x, 0) + 1);
            set.add(x);
        }
        while (set.iterator().hasNext()) {
            int k = set.iterator().next();
            for (int i = k; i < k + W; i++) {
                int v = map.getOrDefault(i, 0);
                if (v > 0) {
                    map.put(i, v - 1);
                    if (v == 1) set.remove(i);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}
