package com.netease.music.leetcode;

import com.netease.music.spring.T;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/5/6
 */
public class Leetcode1038 {

    List<Integer> list = new ArrayList<>();
    List<TreeNode> list2 = new ArrayList<>();

    public TreeNode bstToGst(TreeNode root) {
        dfs(root);
        for (int i = 0; i < list.size(); i++) {
            list2.get(i).val = list.get(i);
        }
        return root;
    }

    private int sum = 0;

    void dfs(TreeNode root) {
        if (root == null) return;
        dfs(root.right);
        sum += root.val;
        list.add(sum);
        list2.add(root);
        dfs(root.left);
    }

}
