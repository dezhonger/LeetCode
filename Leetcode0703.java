//package com.dezhonger.y2019.m06.d01;

import java.util.PriorityQueue;

/**
 * Created by dezhonger on 2019/05/31
 *
 * @author dezhonger
 * @since 2019/05/31
 *
 * 维护一个size=k的小顶堆，堆顶即为答案
 */
public class Leetcode0703 {

    class KthLargest {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
        int k;
        public KthLargest(int k, int[] nums) {
            this.k = k;
            for (int x : nums) {
                priorityQueue.add(x);
                if (priorityQueue.size() > k) {
                    priorityQueue.poll();
                }
            }

        }

        public int add(int val) {
            priorityQueue.add(val);
            if (priorityQueue.size() > k) {
                priorityQueue.poll();
            }
            return priorityQueue.peek();
        }
    }
}
