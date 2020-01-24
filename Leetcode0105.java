package com.dezhonger.y2020.m01.d24;

import com.dezhonger.y2019.TreeNode;

/**
 * Created by dezhonger on 2020/01/24
 *
 * @author dezhonger
 * @since 2020/01/24
 */
public class Leetcode0105 {

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int len = preorder.length;
        return help(0, len - 1, preorder, 0, len - 1, inorder);

    }

    private TreeNode help(int s1, int e1, int[] preorder, int s2, int e2, int[] inorder) {
        //important
        if (s1 > e1) return null;
        if (s2 > e2) return null;
        if (s1 > preorder.length - 1) return null;
        TreeNode root = new TreeNode(preorder[s1]);
        int mid = -1;
        for (int i = s2; i <= e2; i++) {
            if (inorder[i] == root.val) {
                mid = i;
                break;
            }
        }
        root.left = help(s1 + 1, e1, preorder, s2, mid - 1, inorder);
        root.right = help(s1 + 1 + mid - s2, e1, preorder, mid + 1, e2, inorder);
        return root;
    }

}
