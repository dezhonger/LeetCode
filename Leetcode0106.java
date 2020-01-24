package com.dezhonger.y2020.m01.d24;

import com.dezhonger.y2019.TreeNode;

/**
 * Created by dezhonger on 2020/01/24
 *
 * @author dezhonger
 * @since 2020/01/24
 */
public class Leetcode0106 {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int len = inorder.length;
        return help(0, len - 1, inorder, 0, len - 1, postorder);
    }

    private TreeNode help(int s1, int e1, int[] inorder, int s2, int e2, int[] postorder) {
        if (s1 > e1) return null;
        if (s2 > e2) return null;
        if (s1 > inorder.length - 1 || s2 > postorder.length - 1) return null;
        if (e1 < 0 || e2 < 0) return null;
        TreeNode root = new TreeNode(postorder[e2]);
        int mid = -1;

        for (int i = s1; i <= e1; i++) {
            if (inorder[i] == root.val) {
                mid = i;
                break;
            }
        }

        int leftNum = mid - s1;

        root.left = help(s1, mid - 1, inorder, s2, s2 + leftNum - 1, postorder);
        root.right = help(mid + 1, e1, inorder, s2 + leftNum, e2 - 1, postorder);
        return root;
    }
}
