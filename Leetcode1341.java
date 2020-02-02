package com.netease.music.leetcode.contest.no174;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * Created by dezhonger on 2020/2/2
 */
public class Leetcode1341 {


    public int[] kWeakestRows(int[][] mat, int k) {
        List<Node> list = new ArrayList<>();

        for (int i = 0; i < mat.length; i++) {
            list.add(new Node(mat[i], i));
        }
        list.sort(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                long a = o1.f();
                long b = o2.f();
                if (a != b) return Long.compare(a, b);
                return Integer.compare(o1.index, o2.index);
            }
        });

        int[] res = new int[k];
        for (int i = 0; i < k; i++) res[i] = list.get(i).index;
        return res;
    }

    static class Node {
        int[] a;
        int index;

        public Node(int[] a, int index) {
            this.a = a;
            this.index = index;
        }

        private long f() {
            return Arrays.stream(a).filter(e -> e == 1).count();
        }
    }
}
