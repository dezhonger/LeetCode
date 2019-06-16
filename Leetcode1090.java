package com.netease.music.leetcode;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/6/17
 */
public class Leetcode1090 {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        Node[] nodes = new Node[values.length];
        for (int i = 0; i < nodes.length; i++) nodes[i] = new Node(values[i], labels[i]);
        Arrays.sort(nodes);
        int[] cnt = new int[20010];
        int c = 0;
        int s = 0;
        for (int i = 0; c < num_wanted && i < nodes.length; i++) {
            if (cnt[nodes[i].label] < use_limit) {
                s += nodes[i].value;
                cnt[nodes[i].label]++;
                c++;
            }
        }
        return s;
    }

    class Node implements Comparable<Node> {
        Node(int value, int label) {
            this.value = value;
            this.label = label;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(o.value, value);
        }

        int value;
        int label;
    }
}


