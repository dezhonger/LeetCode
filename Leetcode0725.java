package com.dezhonger.y2020.m02.d07;

import com.dezhonger.y2020.ListNode;

/**
 * Created by dezhonger on 2020/02/08
 *
 * @author dezhonger
 * @since 2020/02/08
 */
public class Leetcode0725 {

    public ListNode[] splitListToParts(ListNode root, int k) {
        int len = getLength(root);
        int sl = len / k;
        int a = len - sl * k;


        ListNode[] res = new ListNode[k];
        int index = 0;
        while (index < k) {
            //当前链表的长度
            int curSize = index < a ? sl + 1 : sl;
            res[index++] = root;

            for (int j = 0; j < curSize - 1; j++) {
                if (root != null) root = root.next;
            }

            if (root != null) {
                ListNode tmp = root.next;
                root.next = null;
                root = tmp;
            }
        }
        return res;
    }

    int getLength(ListNode root) {
        if (root == null) return 0;
        int l = 0;
        ListNode r = root;
        while (true) {
            l++;
            r = r.next;
            if (r == null) break;
        }
        return l;
    }

}
