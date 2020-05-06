package com.y2020.m05.d06;

import java.util.Deque;
import java.util.LinkedList;

/**
 * Created by zhangweilong on 2020/05/06
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/05/06
 */
public class Leetcode1438 {

    int[] a;
    //max
    Deque<Integer> d1 = new LinkedList<>();
    //min
    Deque<Integer> d2 = new LinkedList<>();

    void add1(int index) {
        while (!d1.isEmpty() && a[d1.peekLast()] <= a[index]) d1.pollLast();
        d1.add(index);
    }

    void add2(int index) {
        while (!d2.isEmpty() && a[d2.peekLast()] >= a[index]) d2.pollLast();
        d2.add(index);
    }

    void add(int index) {
        add1(index);
        add2(index);
    }

    int getDiff() {
        return a[d1.peekFirst()] - a[d2.peekFirst()];
    }


    public int longestSubarray(int[] nums, int limit) {
        this.a = nums;
        int len = nums.length;
        int l = 0;
        int ans = -1;
        for (int r = 0; r < len; r++) {
            add(r);
            if (getDiff() <= limit) {
                ans = Math.max(ans, r - l + 1);
            } else {
                while (l < r) {
                    while (!d1.isEmpty() && d1.peekFirst() <= l) d1.pollFirst();
                    while (!d2.isEmpty() && d2.peekFirst() <= l) d2.pollFirst();
                    l++;
                    if (getDiff() <= limit) {
                        break;
                    }
                }
            }
        }
        return ans;
    }
}
