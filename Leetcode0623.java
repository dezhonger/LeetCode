package com.dezhonger.y2020.m01.d09;

import com.dezhonger.y2019.TreeNode;

/**
 * Created by dezhonger on 2020/01/09
 *
 * @author dezhonger
 * @since 2020/01/09
 */
public class Leetcode0623 {
    int v;
    int d;

    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if (d == 1) {
            TreeNode r = new TreeNode(v);
            r.left = root;
            return r;
        }
        this.v = v;
        this.d = d;
        dfs(root, 1);
        return root;
    }

    private void dfs(TreeNode root, int dep) {
        if (root == null) return;
        if (dep + 1 == d) {
            TreeNode l = new TreeNode(v);
            l.left = root.left;
            root.left = l;

            TreeNode r = new TreeNode(v);
            r.right = root.right;
            root.right = r;
        } else if (dep +1 < d) {
            dfs(root.left, dep + 1);
            dfs(root.right, dep + 1);
        }
    }
}
