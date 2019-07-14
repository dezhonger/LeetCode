package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/7/14
 */
public class Leetcode1124 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1124().longestWPI(new int[]{9, 9, 6, 0, 6, 6, 9}));
    }


    public int longestWPI(int[] hours) {
        for (int i = 0; i < hours.length; i++) hours[i] = hours[i] > 8 ? 1 : -1;
        List<Integer> list = new ArrayList<>();
        List<Node> nodes = new ArrayList<>();
        list.add(0);
        nodes.add(new Node(0, 0));
        int ans = 0;
        for (int x : hours) {
            int val = list.get(list.size() - 1) + x;
            list.add(val);

            int l = 0;
            int r = nodes.size() - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (nodes.get(mid).val < val) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (nodes.get(l).val < val) {

                ans = Math.max(ans, list.size() - nodes.get(l).pos - 1);
            }
            if (val < nodes.get(nodes.size() - 1).val) {
                nodes.add(new Node(val, list.size() - 1));
            }
        }
        return ans;
    }

    class Node {
        int val;
        int pos;

        public Node(int val, int pos) {
            this.val = val;
            this.pos = pos;
        }
    }
}
