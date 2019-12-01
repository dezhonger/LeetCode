package com.y2019.m11.d30;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Created by zhangweilong on 2019/12/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/01
 */
public class Leetcode0433 {

    public int minMutation(String start, String end, String[] bank) {
        Set<String> set = new HashSet<>();
        Map<String, Integer> map = new HashMap<>();
        set.add(start);
        for (String s : bank) set.add(s);
        if (!set.contains(end)) return -1;
        int size = set.size();
        int k = 0;
        for (String s : set) {
            map.put(s, k++);
        }

        //build graph
        int[][] graph = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                graph[i][j] = 100_0000;
                if (i == j) graph[i][j] = 0;
            }
        }
        for (String s1 : set) {
            for (String s2 : set) {
                if (!s1.equals(s2)) {
                    boolean c = check(s1, s2);
                    if (c) {
                        int i1 = map.get(s1);
                        int i2 = map.get(s2);
                        graph[i1][i2] = graph[i2][i1] = 1;
                    }
                }
            }
        }

        //cal
        for (int kk = 0; kk < size; kk++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (graph[i][kk] + graph[kk][j] < graph[i][j]) graph[i][j] = graph[i][kk] + graph[kk][j];
                }
            }
        }
        int res =graph[map.get(start)][map.get(end)];
        if (res == 100_0000) res = -1;
        return res;
    }
    private boolean check(String s1, String s2) {
        int c = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) c++;
        }
        return 1 == c;
    }
}
