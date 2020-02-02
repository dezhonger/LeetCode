package com.netease.music.leetcode.contest.no174;

import com.netease.music.leetcode.TreeNode;

/**
 * Created by dezhonger on 2020/2/2
 */
public class Leetcode1343 {

    long res = -1;

    public int maxProduct(TreeNode root) {
        long sum = dfs(root);
        dfs2(root, sum);
        return (int) (res % 10_0000_0007);
    }


    private long dfs(TreeNode root) {
        if (root == null) return 0;
        long l = dfs(root.left);
        long r = dfs(root.right);
        long res = root.val + l + r;
        return res;
    }


    private long dfs2(TreeNode root, long sum) {
        if (root == null) return 0;
        long l = dfs2(root.left, sum);
        long r = dfs2(root.right, sum);
        long cur = root.val + l + r;
        if (cur != sum) {
            //exclude root node
            long b = sum - cur;
            res = Math.max(res, b * cur);
        }
        return cur;
    }
}
