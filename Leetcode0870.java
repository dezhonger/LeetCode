package com.y2020.m01.d11;

import com.y2018.m01.d17.A;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.TreeMap;

/**
 * Created by zhangweilong on 2020/01/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/11
 */
public class Leetcode0870 {
    public int[] advantageCount(int[] A, int[] B) {
        int len = A.length;
        Arrays.sort(A);
        //递减的一个优先队列
        int[] res = new int[len];
        Queue<int[]> q = new PriorityQueue<>((o1, o2) -> Integer.compare(o2[0], o1[0]));
        for (int i = 0; i < len; i++) q.add(new int[]{B[i], i});
        int l = 0, r = len - 1;
        while(!q.isEmpty()) {
            int[] poll = q.poll();
            int v = poll[0];
            int idx = poll[1];
            if (A[r] > v) {
                res[idx] = A[r];
                r--;
            } else {
                res[idx] = A[l];
                l++;
            }
        }
        return res;
    }
}
