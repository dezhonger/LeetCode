package com.netease.music.p20200212;

import com.google.common.collect.Lists;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

/**
 * Created by dezhonger on 2020/2/12
 */
public class Leetcode0632 {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Leetcode0632().smallestRange(
                Lists.newArrayList(
                        Lists.newArrayList(4,10,15,24,26),
                        Lists.newArrayList(0,9,12,20),
                        Lists.newArrayList(5,18,22,30)
                )
        )));
    }
    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return Integer.compare(o1.val, o2.val);
            }
        });
        int len = nums.size();
        int res = Integer.MAX_VALUE;

        //当前队列里的最大值
        int max = Integer.MIN_VALUE;
        int minNum = Integer.MIN_VALUE;
        int maxNum = Integer.MIN_VALUE;
        for (int i = 0; i < len; i++) {
            int x = nums.get(i).get(0);
            pq.add(new Node(i, 0, x));
            max = Math.max(max, x);
        }

        while (pq.size() == len) {
            Node mi = pq.poll();
            if (max - mi.val < res) {
                res = max - mi.val;
                minNum = mi.val;
                maxNum = max;
            }
            if (mi.index < nums.get(mi.group).size() - 1) {
                int x = nums.get(mi.group).get(mi.index + 1);
                pq.add(new Node(mi.group, mi.index + 1, x));
                max = Math.max(max, x);
            }
        }
        return new int[]{minNum, maxNum};
    }


    class Node {
        int group;
        int index;
        int val;

        public Node(int group, int index, int val) {
            this.group = group;
            this.index = index;
            this.val = val;
        }
    }
}
