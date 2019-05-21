package com.netease.music.leetcode;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/5/21
 */
public class Leetcode0965 {
    public boolean isUnivalTree(TreeNode root) {
        Set<Integer> set = new HashSet<>();
        dfs(set, root);
        return set.size() <= 1;
    }

    private void dfs(Set<Integer> set, TreeNode root) {
        if (root == null) return;
        set.add(root.val);
        dfs(set, root.left);
        dfs(set, root.right);

    }
}
