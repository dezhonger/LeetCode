package com.dezhonger.y2020.m01.d19;

import com.dezhonger.y2019.TreeNode;

/**
 * Created by dezhonger on 2020/01/18
 *
 * @author dezhonger
 * @since 2020/01/18
 *
 *
 */
public class Leetcode0979 {
    int res = 0;
    public int distributeCoins(TreeNode root) {
        cal(root);
        return res;
    }

    private void cal(TreeNode root) {
        if (root == null) return;
        int[] left = new int[2];
        dfs(root.left, left);
        res += Math.abs(left[0] - left[1]);

        int[] right = new int[2];
        dfs(root.right, right);
        res += Math.abs(right[0] - right[1]);

        cal(root.left);
        cal(root.right);
    }

    //c[0] 节点数, c[1] 硬币数量
    private void dfs(TreeNode root, int[] c) {
        if (root == null) return;
        c[0]++;
        c[1] += root.val;
        dfs(root.left, c);
        dfs(root.right, c);
    }
}
