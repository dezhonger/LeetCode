package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/12/29
 */
public class Leetcode1302 {
    int depth;
    int sum;
    public int deepestLeavesSum(TreeNode root) {
        depth = -1;
        sum = 0;
        dfs1(root, 1);
        dfs2(root, 1);
        return sum;
    }

    private void dfs2(TreeNode root, int d) {
        if (root == null) return;
        if (d == depth) sum += root.val;
        dfs2(root.left, d + 1);
        dfs2(root.right, d + 1);
    }

    private void dfs1(TreeNode root, int d) {
        if (root == null) return;
        depth = Math.max(depth, d);
        dfs1(root.left, d + 1);
        dfs1(root.right, d + 1);
    }
}
