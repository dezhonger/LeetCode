package com.dezhonger.y2019.m05;


import com.dezhonger.y2019.TreeNode;

/**
 * Created by dezhonger on 2019/05/08
 *
 * @author dezhonger
 * @since 2019/05/08
 */
public class Leetcode0938 {
    int s = 0;

    public int rangeSumBST(TreeNode root, int L, int R) {
        s = 0;
        dfs(root, L, R);
        return s;
    }

    private void dfs(TreeNode root, int l, int r) {
        if (root == null) return;
        dfs(root.right, l, r);
        if (root.val >= l && root.val <= r) s += root.val;
        dfs(root.left, l, r);

    }
}