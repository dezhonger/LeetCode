package com.dezhonger.y2020.m02.d11;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

/**
 * Created by dezhonger on 2020/02/11
 *
 * @author dezhonger
 * @since 2020/02/11
 * leetcode981
 */
public class TimeMap {
    Map<String, TreeMap<Integer, String>> map;

    /** Initialize your data structure here. */
    public TimeMap() {
        map = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {
        TreeMap<Integer, String> treeMap = map.getOrDefault(key, new TreeMap<>());
        treeMap.put(timestamp, value);
        map.put(key, treeMap);
    }

    public String get(String key, int timestamp) {
        TreeMap<Integer, String> treeMap = map.get(key);
        if (treeMap == null) return "";
        Integer k = treeMap.floorKey(timestamp);
        if (k == null) return "";
        return treeMap.get(k);
    }
}
