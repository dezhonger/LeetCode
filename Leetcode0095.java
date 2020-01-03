package com.y2020.m01.d03;

import com.y2020.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangweilong on 2020/01/03
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/03
 */
public class Leetcode0095 {
    public static void main(String[] args) {
        new Leetcode0095().generateTrees(3);
    }
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) return new ArrayList<>();
        return dfs(1, n);
    }

    private List<TreeNode> dfs(int l, int r) {
        List<TreeNode> res = new ArrayList<>();
        if (l > r) {
            res.add(null);
            return res;
        }
        if (l == r) {
            res.add(new TreeNode(l));
            return res;
        }

        for (int i = l; i <= r; i++) {
            List<TreeNode> left = dfs(l, i - 1);
            List<TreeNode> right = dfs(i + 1, r);
            for (TreeNode lr : left) {
                for (TreeNode rr : right) {
                    TreeNode treeNode = new TreeNode(i);
                    treeNode.left = lr;
                    treeNode.right = rr;
                    res.add(treeNode);
                }
            }

        }
        return res;
    }
}
