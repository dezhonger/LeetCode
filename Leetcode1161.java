package com.netease.music.p20190819;


/**
 * Created by dezhonger on 2019/8/19
 */
public class Leetcode1161 {
    int[] cnt = new int[10005];
    int maxdep = 0;

    public int maxLevelSum(TreeNode root) {
        go(root, 1);
        int best = Integer.MIN_VALUE;
        int arg = 0;
        for (int i = 1; i <= maxdep; i++) {
            if (cnt[i] > best) {
                best = cnt[i];
                arg = i;
            }
        }
        return arg;
    }

    void go(TreeNode root, int dep) {
        if (root == null) return;
        maxdep = Math.max(maxdep, dep);
        cnt[dep] += root.val;
        go(root.left, dep + 1);
        go(root.right, dep + 1);
    }
}
