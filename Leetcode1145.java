package com.dezhonger.y2020.m01.d25;

import com.dezhonger.y2019.TreeNode;

/**
 * Created by dezhonger on 2020/01/25
 *
 * @author dezhonger
 * @since 2020/01/25
 */
public class Leetcode1145 {
    int p, l, r;
    int n, x;
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        p = l = r = 0;
        this.n = n;
        this.x = x;
        dfs(root);
        return Math.max(Math.max(l, r), n - l - r - 1) > n / 2;
    }

    private int dfs(TreeNode root) {
        if (root == null) return 0;
        int l = dfs(root.left);
        int r = dfs(root.right);
        if (root.val == x) {
            this.l = l;
            this.r = r;
        }
        return l + r + 1;
    }
}
