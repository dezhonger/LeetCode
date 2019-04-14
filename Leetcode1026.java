package com.netease.music.leetcode.contest.no132;

/**
 * Created by dezhonger on 2019/4/14
 */
public class Leetcode1026 {
    int ret = 0;
    public int maxAncestorDiff(TreeNode root) {
        ret = 0;
        dfs(root, root.val, root.val);
        return ret;
    }

    void dfs(TreeNode cur, int max, int min)
    {
        if(cur == null)return;
        ret = Math.max(ret, Math.abs(max-cur.val));
        ret = Math.max(ret, Math.abs(min-cur.val));

        dfs(cur.left, Math.max(max, cur.val), Math.min(min, cur.val));
        dfs(cur.right, Math.max(max, cur.val), Math.min(min, cur.val));
    }
}
