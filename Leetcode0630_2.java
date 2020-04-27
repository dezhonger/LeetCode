package com.netease.music.leetcode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * Created by dezhonger on 2020/04/27
 */
public class Leetcode0630_2 {
    public int scheduleCourse(int[][] courses) {
        Arrays.sort(courses, Comparator.comparingInt(o -> o[1]));
        int time = 0;
        int len = courses.length;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < len; i++) {
            if (time + courses[i][0] <= courses[i][1]) {
                time += courses[i][0];
                pq.add(-courses[i][0]);
            } else {
                if (!pq.isEmpty() && pq.peek() < -courses[i][0]) {
                    time += pq.peek();
                    pq.poll();
                    time += courses[i][0];
                    pq.add(-courses[i][0]);
                }
            }
        }
        return pq.size();
    }
}
