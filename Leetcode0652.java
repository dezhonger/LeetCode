package com.netease.music.leetcode;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by dezhonger on 2020/1/5
 */
public class Leetcode0652 {
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        List<TreeNode> res = new LinkedList<>();
        dfs(root, new HashMap<>(), res);
        return res;
    }

    private String dfs(TreeNode root, HashMap<String, Integer> map, List<TreeNode> res) {
        if (root == null) return "#";
        String string = new StringBuilder().append(root.val).append(",").append(dfs(root.left, map, res)).append(",").append(dfs(root.right, map, res)).toString();
        int cnt = map.getOrDefault(string, 0);
        if (cnt == 1) res.add(root);
        map.put(string, cnt + 1);
        return string;
    }

}
