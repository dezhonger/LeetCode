package com.netease.music.leetcode.contest.no174;

import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

/**
 * Created by dezhonger on 2020/2/2
 */
public class Leetcode1342 {
    public int minSetSize(int[] arr) {
        int len = arr.length;
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>(new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return Integer.compare(o2.getValue(), o1.getValue());
            }
        });

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < len; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }
        pq.addAll(map.entrySet());
        int c = 0;
        int res = 0;
        while (true) {
            c += pq.poll().getValue();
            res++;
            if (c >= len / 2) break;
        }
        return res;
    }
}
