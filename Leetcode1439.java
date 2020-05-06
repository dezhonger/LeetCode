package com.netease.music.leetcode.hard;

import java.util.Arrays;
import java.util.PriorityQueue;

/**
 * Created by dezhonger on 2020/05/06
 */
public class Leetcode1439 {
    public static void main(String[] args) {
//        System.out.println(new Leetcode1439().kthSmallest(new int[][]{
//                {1,3,11},
//                {2,4,6},
//        }, 5));

//        System.out.println(new Leetcode1439().kthSmallest(new int[][]{
//                {1, 3, 11},
//                {2, 4, 6},
//        }, 9));

        System.out.println(new Leetcode1439().kthSmallest(new int[][]{
                {1, 10,10},
                {1, 4,5},
                {2, 3, 6},
        }, 14));
    }


    int[] merge(int[] a, int[] b, int k) {
        int[] res = new int[Math.min(k, a.length * b.length)];
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(0, 0, a[0] + b[0], false));
        int index = 0;
        while (index < k && !pq.isEmpty()) {
            Node x = pq.poll();
            res[index++] = x.v;
            if (x.j + 1 < b.length) pq.add(new Node(x.i, x.j + 1, a[x.i] + b[x.j + 1], true));
            if (!x.flag && x.i + 1 < a.length) pq.add(new Node(x.i + 1, x.j, a[x.i + 1] + b[x.j], false));
        }

        return res;
    }

    public int kthSmallest(int[][] mat, int k) {
        int[] last = mat[0];
        for (int i = 1; i < mat.length; i++) {
            last = merge(last, mat[i], k);
        }
        System.out.println(Arrays.toString(last));
        return last[k - 1];
    }


    class Node implements Comparable<Node> {

        int i, j;
        int v;
        boolean flag;

        public Node(int i, int j, int v, boolean flag) {
            this.i = i;
            this.j = j;
            this.v = v;
            this.flag = flag;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(v, o.v);
        }
    }
}
