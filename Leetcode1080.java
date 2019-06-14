package com.y2019.m06.d15;

import com.y2018.m01.d09.T;
import sun.reflect.generics.tree.Tree;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

/**
 * Created by zhangweilong on 2019/06/14
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/06/14
 */


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class Leetcode1080 {

    Map<TreeNode, TreeNode> mapParent = new HashMap<>();
    Map<TreeNode, Integer> mapValue = new HashMap<>();
    Set<TreeNode> isLeaf = new HashSet<>();
    List<TreeNode> list = new ArrayList<>();
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        dfs(root, null, 0);

        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode poll = queue.poll();
            list.add(poll);
            if (poll.left != null) queue.add(poll.left);
            if (poll.right != null) queue.add(poll.right);
            if (poll.left == null && poll.right == null) isLeaf.add(poll);
        }
        Collections.reverse(list);
        for (TreeNode treeNode : list) {
            if (treeNode.right == null && treeNode.left == null) {
                //leaf node
                if (isLeaf.contains(treeNode)) {
                    if (mapValue.get(treeNode) < limit) {
                        TreeNode parent = mapParent.get(treeNode);
                        if (parent != null) {
                            if (treeNode.equals(parent.left)) parent.left = null;
                            if (treeNode.equals(parent.right)) parent.right = null;
                        } else {
                            //只有根没有父亲
                            root = null;
                        }
                    }
                } else {
                    if (treeNode.left == null && treeNode.right == null) {
                        TreeNode parent = mapParent.get(treeNode);
                        if (parent != null) {
                            if (treeNode.equals(parent.left)) parent.left = null;
                            if (treeNode.equals(parent.right)) parent.right = null;
                        } else {
                            //只有根没有父亲
                            root = null;
                        }
                    }
                }
            }
        }
        return root;
    }


    private void dfs(TreeNode root, TreeNode parent, int x) {
        if (root == null) return;
        mapParent.put(root, parent);
        mapValue.put(root, root.val + x);
        dfs(root.left, root, root.val + x);
        dfs(root.right, root, root.val + x);
    }
}
