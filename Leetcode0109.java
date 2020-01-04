package com.y2020.m01.d04;

import com.y2020.ListNode;
import com.y2020.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangweilong on 2020/01/04
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/04
 */
public class Leetcode0109 {
    ListNode cur;

    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) return null;
        int size = 0;
        ListNode t = head;
        cur = head;
        while (t != null) {
            size++;
            t = t.next;
        }

        return construct(1, size);
    }

    private TreeNode construct(int l, int r) {
        if (l > r) return null;
        int mid = (l + r) / 2;

        TreeNode left = construct(l, mid - 1);
        TreeNode root = new TreeNode(cur.val);
        root.left = left;
        cur = cur.next;
        root.right = construct(mid + 1, r);
        return root;
    }

}
