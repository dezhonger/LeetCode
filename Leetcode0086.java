package com.netease.music.gyarados.utils;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangweilong on 2019/08/31
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/08/31
 */
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

public class Leetcode0086 {
    public ListNode partition(ListNode head, int x) {
        List<ListNode> r = new ArrayList<>();
        if (head == null) return null;
        while(true) {
            r.add(head);
            head = head.next;
            if (head == null) break;
        }
        List<ListNode> r1 = new ArrayList<>();
        List<ListNode> r2 = new ArrayList<>();

        for (ListNode l : r) {
            if (l.val < x) r1.add(l);
            else r2.add(l);
        }
        if (r1.size() == 0) return r2.get(0);
        if (r2.size() == 0) return r1.get(0);
        for (int i = 1; i < r1.size(); i++) r1.get(i - 1).next = r1.get(i);
        for (int i = 1; i < r2.size(); i++) r2.get(i - 1).next = r2.get(i);
        r1.get(r1.size() - 1).next = r2.get(0);
        r2.get(r2.size() - 1).next = null;
        return r1.get(0);
    }
}
