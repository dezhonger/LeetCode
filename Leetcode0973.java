package com.netease.music.leetcode;

import org.omg.CORBA.INTERNAL;

import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * Created by dezhonger on 2019/3/28
 *
 * min heap
 */
public class Leetcode0973 {

    class A {
        public A(int index, int x, int y, int z) {
            this.index = index;
            this.x = x;
            this.y = y;
            this.z = z;
        }

        int index;
        int x, y;
        int z;
    }

    public static void main(String[] args) {
        new Leetcode0973().kClosest(null, 1);
    }

    public int[][] kClosest(int[][] points, int K) {
        PriorityQueue<A> queue = new PriorityQueue<>(new Comparator<A>() {
            @Override
            public int compare(A o1, A o2) {
                return Integer.compare(o2.z, o1.z);
            }
        });
        A[] arr = new A[points.length];
        for (int i = 0; i < points.length; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int z = x * x + y * y;
            A a = new A(i, x, y, z);
            arr[i] = a;
            queue.add(a);
            if (queue.size() > K) queue.poll();
        }
        int[][] r = new int[K][2];
        int cnt = 0;
        while (!queue.isEmpty()) {
            A poll = queue.poll();
            r[cnt][0] = poll.x;
            r[cnt++][1] = poll.y;
        }
        return r;
    }
}
