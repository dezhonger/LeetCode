package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/6/22
 */
public class Leetcode0993 {
    int[] p = new int[2];
    int[] d = new int[2];
    public boolean isCousins(TreeNode root, int x, int y) {
        dfs(root, -1, x, 1, 0);
        dfs(root, -1, y, 1, 1);
        return d[0] == d[1] && p[0] != p[1];
    }

    private void dfs(TreeNode root, int pa, int x, int depth, int index) {
        if (root == null) return;
        if (root.val == x) {
            d[index] = depth;
            p[index] = pa;
        }
        dfs(root.left, root.val, x, depth + 1, index);
        dfs(root.right, root.val, x,depth + 1, index);
    }
}
