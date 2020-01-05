package com.dezhonger.y2020.m01;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.TreeMap;
import java.util.stream.Collectors;

/**
 * Created by dezhonger on 2020/01/05
 *
 * @author dezhonger
 * @since 2020/01/05
 */
public class Leetcode1311 {
    public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{id, 0});
        boolean[] v = new boolean[friends.length];
        v[id] = true;
        Map<String, Integer> res = new HashMap<>();
        while (!q.isEmpty()) {
            int[] poll = q.poll();
            int f = poll[0];
            int step = poll[1];
            if (step >= level) continue;
            for (int i = 0; i < friends[f].length; i++) {
                int fr = friends[f][i];
                if (v[fr] == false) {
                    v[fr] = true;
                    if (step + 1 == level) {
                        List<String> strings = watchedVideos.get(fr);
                        for (String string : strings) {
                            res.put(string, res.getOrDefault(string, 0) + 1);
                        }
                    } else {
                        q.add(new int[]{fr, step + 1});
                    }
                }
            }
        }
        List<Node> list = new ArrayList<>();
        res.forEach((k, g) -> {
            list.add(new Node(k, g));
        });

        Collections.sort(list, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if (o1.c != o2.c) return Integer.compare(o1.c, o2.c);
                return o1.v.compareTo(o2.v);
            }
        });

        return list.stream().map(e -> e.v).collect(Collectors.toList());
    }

    class Node {
        public Node(String v, int c) {
            this.v = v;
            this.c = c;
        }

        String v;
        int c;
    }
}
