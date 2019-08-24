//package com.y2019.m08.d24;


import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangweilong on 2019/08/24
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/08/24
 */
public class Leetcode0092 {
    // 0-1-2-3-4 m=2.n=4
    //m-- = 1 n-- =3
    //0-3-2-1-4

    public ListNode reverseBetween(ListNode head, int m, int n) {
        List<ListNode> a = new ArrayList<>();
        while (true) {
            a.add(head);
            head = head.next;
            if (head == null) break;
        }
        m--;
        n--;
        for (int i = m, j = n; i < j; i++, j--) {
            ListNode tmp = a.get(i);
            a.set(i, a.get(j));
            a.set(j, tmp);
        }
        for (int i = 1; i < a.size(); i++) {
            a.get(i - 1).next = a.get(i);
        }
        a.get(a.size() - 1).next = null;
        return a.get(0);
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}
