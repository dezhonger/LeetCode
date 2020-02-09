package com.dezhonger.y2020.m02.d10;

import com.dezhonger.y2020.ListNode;

/**
 * Created by dezhonger on 2020/02/10
 *
 * @author dezhonger
 * @since 2020/02/10
 */
public class Leetcode0082 {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;
        ListNode h = new ListNode(-2);
        h.next = head;

        ListNode pre = h;
        ListNode cur;

        ListNode res = new ListNode(-1);
        ListNode result = res;


        while (true) {
            cur = pre.next;
            if (cur == null) break;

            if (cur.next != null) {
                if (cur.val != pre.val && cur.val != cur.next.val) {
                    ListNode t = new ListNode(cur.val);
                    res.next = t;
                    res = t;
                    pre = cur;
                } else {
                    pre = cur;
                }
            } else {
                if (cur.val != pre.val) {
                    ListNode t = new ListNode(cur.val);
                    res.next = t;
                    res = t;
                    pre = cur;
                } else {
                    pre = cur;
                }
            }
        }

        return result.next;
    }
}
