package com.netease.music.leetcode.design.leetcode0146;

import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Set;

/**
 * Created by dezhonger on 2019/11/27
 */
public class LRUCache_0146 {

    int capacity;
    Map<Integer, Integer> map;
    Set<Integer> set;

    public LRUCache_0146(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>(capacity);
        set = new LinkedHashSet<>();
    }

    public int get(int key) {
        int res = map.getOrDefault(key, -1);
        if (res == -1) {
            return -1;
        } else {
            set.remove(key);
            set.add(key);
            return res;
        }

    }

    public void put(int key, int value) {
        if (set.size() < capacity) {
            if (map.containsKey(key)) {
                map.put(key, value);
                set.remove(key);
                set.add(key);
            } else {
                map.put(key, value);
                set.add(key);
            }
        } else {
            if (map.containsKey(key)) {
                map.put(key, value);
                set.remove(key);
                set.add(key);
            } else {
                int evictsKey = set.iterator().next().intValue();
                map.remove(evictsKey);
                map.put(key, value);
                set.remove(evictsKey);
                set.add(key);
            }
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
