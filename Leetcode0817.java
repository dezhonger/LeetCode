package com.netease.music.leetcode;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2020/1/4
 */
public class Leetcode0817 {
    public int numComponents(ListNode head, int[] G) {
        if (head == null) return 0;
        Set<Integer> set = new HashSet<>();
        for (int x : G) set.add(x);
        int res = 0;
        while (head != null) {
            if (set.contains(head.val) && (head.next == null || !set.contains(head.next.val))) res++;
            head = head.next;
        }
        return res;
    }
}
