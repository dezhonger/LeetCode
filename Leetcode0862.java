package com.y2020.m01.d29;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * Created by zhangweilong on 2020/02/29
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/02/29
 */
public class Leetcode0862 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0862().shortestSubarray(new int[]{1}, 1));
        System.out.println(new Leetcode0862().shortestSubarray(new int[]{1, 2}, 4));
        System.out.println(new Leetcode0862().shortestSubarray(new int[]{2, -1, 2}, 3));

    }
    public int shortestSubarray(int[] A, int K) {
        //单调队列，维护前缀和B[], 如果 B[i] >= B[j]， 那么i永远不可能成为最有解
        int len = A.length;
        int[] b = new int[len + 1];
        for (int i = 1; i <= len; i++) b[i] = b[i - 1] + A[i - 1];

        int res = Integer.MAX_VALUE;
        //d是一个双端队列，维护的是b数组的下标
        Deque<Integer> d = new ArrayDeque<>();
        d.add(0);
        for (int i = 1; i <= len; i++) {
            while (!d.isEmpty() && b[i] - b[d.getFirst()] >= K) {
                res = Math.min(res, i - d.getFirst());
                d.pollFirst();
            }
            //根据上述的性质，队列维护的前缀和一定是一个(严格)单调上升的
            while (!d.isEmpty() && b[i] <= b[d.getLast()]) {
                d.pollLast();
            }
            d.add(i);
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }



}
