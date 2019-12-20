package com.netease.music.leetcode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

/**
 * Created by dezhonger on 2019/12/20
 */
public class Leetcode0127 {

    Map<String, Integer> map1 = new HashMap<>();
    Map<Integer, String> map2 = new HashMap<>();

    int c;

    private void init(String beginWord, String endWord, List<String> wordList) {
        c = 0;
        map1.put(beginWord, c);
        map2.put(c, beginWord);
        c++;
        for (int i = 0; i < wordList.size(); i++) {
            String str = wordList.get(i);
            map1.put(str, c);
            map2.put(c, str);
            c++;
        }
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        boolean f = false;
        for (String s : wordList) {
            if (s.equals(endWord)) {
                f = true;
                break;
            }
        }
        if (!f) return 0;
        init(beginWord, endWord, wordList);

        List<List<Integer>> list = new ArrayList<>();
        for (int i = 0; i < c; i++) list.add(new ArrayList<>());

        for (int i = 0; i < wordList.size(); i++) {
            String str = wordList.get(i);
            if (can(beginWord, str)) {
                list.get(0).add(i + 1);
                list.get(i + 1).add(0);
            }
        }

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                String s1 = wordList.get(i);
                String s2 = wordList.get(j);
                if (can(s1, s2)) {
                    list.get(i + 1).add(j + 1);
                    list.get(j + 1).add(i + 1);
                }
            }
        }


        //建图完毕，开始计算
        Node node = new Node(beginWord, 0, 1);
        Queue<Node> queue = new ArrayDeque<>();
        queue.add(node);
        Set<Integer> set = new HashSet<>();
        set.add(0);

        while (!queue.isEmpty()) {
            Node poll = queue.poll();
            int step = poll.step;
            if (poll.s.equals(endWord)) {
                return step;
            }
            List<Integer> integers = list.get(poll.v);
            for (int i = 0; i < integers.size(); i++) {
                Integer in = integers.get(i);
                if (!set.contains(in)) {
                    String ss = map2.get(in);
                    Node n = new Node(ss, in, step + 1);
                    queue.add(n);
                    set.add(in);
                }
            }
        }
        return 0;
    }


    private boolean can(String a, String b) {
        int x = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) x++;
            if (x >= 2) return false;
        }
        return x == 1;
    }


    private static class Node {
        String s;
        int v;
        int step;
        public Node(String s, int v, int step) {
            this.s = s;
            this.v = v;
            this.step = step;
        }
    }

}
