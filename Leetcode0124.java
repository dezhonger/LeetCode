package com.y2020.m04.d20;

import com.y2020.TreeNode;

/**
 * Created by zhangweilong on 2020/04/20
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/04/20
 */
public class Leetcode0124 {
    int ans = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int dfs(TreeNode root) {
        if (root == null) return 0;
        int l = dfs(root.left);
        int r = dfs(root.right);
        ans = Math.max(ans, Math.max(Math.max(root.val, root.val + l + r), Math.max(root.val + l, root.val + r)));
        return Math.max(root.val, Math.max(root.val + l, root.val + r));
    }
}
