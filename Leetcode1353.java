package com.netease.music.p20200216;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * Created by dezhonger on 2020/2/16
 */
public class Leetcode1353 {
    public int maxEvents(int[][] A) {
        int res = 0;
        Arrays.sort(A, Comparator.comparingInt(o -> o[0]));
        //维护任务的结束时间
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        //枚举任务的开始时间
        int i = 0;
        for (int d = 1; d <= 100000; d++) {
            //把第i天开始的任务的结束时间放到优先队列,优先队列按照任务的结束时间从小到大排序
            while (i < A.length && A[i][0] == d) pq.add(A[i++][1]);

            //抛掉已经无法完成的任务(这些任务的结束时间在d之前
            while (!pq.isEmpty() && pq.peek() < d) pq.poll();

            //完成截止日期最短的任务
            if (!pq.isEmpty()) {
                res++;
                pq.poll();
            }
            //优化
            if (res == A.length) break;
        }
        return res;
    }

}
