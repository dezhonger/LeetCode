package com.dezhonger.y2020.m01.d25;

import com.dezhonger.y2019.TreeNode;

/**
 * Created by dezhonger on 2020/01/25
 *
 * @author dezhonger
 * @since 2020/01/25
 */
public class Leetcode0450 {
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        if (key > root.val) root.right = deleteNode(root.right, key);
        else if (key < root.val) root.left = deleteNode(root.left, key);
        else {
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;
            TreeNode tmp = root.left;
            while (tmp.right != null) tmp = tmp.right;
            tmp.right = root.right;
            return root.left;
        }
        return root;
    }

}
