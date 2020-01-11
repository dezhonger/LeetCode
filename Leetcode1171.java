package com.y2020.m01.d11;

import com.y2020.ListNode;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by zhangweilong on 2020/01/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/11
 */
public class Leetcode1171 {
    public static void main(String[] args) {
        Leetcode1171 sol = new Leetcode1171();
        ListNode l1 = new ListNode(2);
        ListNode l2 = new ListNode(2);
        ListNode l3 = new ListNode(-2);
        ListNode l4 = new ListNode(1);
        ListNode l5 = new ListNode(-1);
        ListNode l6 = new ListNode(-1);
        ListNode l7 = new ListNode(5);
        ListNode l8 = new ListNode(-5);
        ListNode l9 = new ListNode(1);
        l1.next = l2;
        l2.next = l3;
        l3.next = l4;
        l4.next = l5;
        l5.next = l6;
//        l6.next = l7;
//        l7.next = l8;
//        l8.next = l9;
        sol.removeZeroSumSublists(l1);
    }

    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode root = new ListNode(0), cur = root;
        root.next = head;
        int prefix = 0;
        Map<Integer, ListNode> m = new HashMap<>();
        while (cur != null) {
            prefix += cur.val;
            if (m.containsKey(prefix)) {
                ListNode last = m.get(prefix);
                //要把中间节点的节点对应的前缀和从map移除掉
                ListNode lk = last;
                int sum = prefix;
                while (last.next != cur) {
                    last = last.next;
                    sum += last.val;
                    m.remove(sum);
                }

                lk.next = cur.next;

            } else {
                m.put(prefix, cur);
            }
            cur = cur.next;
        }
        return root.next;
    }
}
