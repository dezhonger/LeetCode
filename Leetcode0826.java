package com.dezhonger.y2020.m01.d28;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2020/01/29
 *
 * @author dezhonger
 * @since 2020/01/29
 */

public class Leetcode0826 {

    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int len = difficulty.length;
        List<Node> list = new ArrayList<>();
        List<Node> list2 = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            list.add(new Node(difficulty[i], profit[i]));
        }
        Collections.sort(list);
        int lastProfit = -1;
        for (int i = 0; i < len; i++) {
            Node node = list.get(i);
            if (node.profit > lastProfit) {
                lastProfit = node.profit;
                list2.add(node);
            }
        }
        System.out.println();
        int res = 0;
        Arrays.sort(worker);
        int j = 0;
        for (int i = 0; i < worker.length; i++) {
            //找到最大收益的
            while (j < list2.size() - 1 && list2.get(j + 1).diff <= worker[i]) j++;
            if (list2.get(j).diff <= worker[i]) res += list2.get(j).profit;
        }
        return res;
    }

    class Node implements Comparable<Node> {

        int diff;
        int profit;

        public Node(int diff, int profit) {
            this.diff = diff;
            this.profit = profit;
        }

        @Override
        public int compareTo(Node o) {
            if (diff != o.diff) return Integer.compare(diff, o.diff);
            return Integer.compare(o.profit, profit);
        }
    }
}
