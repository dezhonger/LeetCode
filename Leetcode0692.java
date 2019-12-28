package com.y2019.m12.d28.num692;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

/**
 * Created by zhangweilong on 2019/12/28
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/28
 */
public class Leetcode0692 {
    //Try to solve it in O(n log k) time and O(n) extra space.
    public List<String> topKFrequent(String[] words, int k) {
        List<String> res = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }

        PriorityQueue<Map.Entry<String, Integer>> q = new PriorityQueue<>(
                (o1, o2) -> {
                    if (o1.getValue() == o2.getValue()) return o2.getKey().compareTo(o1.getKey());
                    return Integer.compare(o1.getValue(), o2.getValue());
                }
        );
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            q.offer(entry);
            if (q.size() > k) q.poll();
        }
        while(!q.isEmpty()) res.add(0, q.poll().getKey());
        return res;
    }
}
