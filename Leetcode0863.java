package com.y2020.m01.d07;

import com.y2020.TreeNode;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

/**
 * Created by zhangweilong on 2020/01/07
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/07
 */
public class Leetcode0863 {

    Map<TreeNode, TreeNode> parent = new HashMap<>();
    int t;
    TreeNode start;

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        this.t = target.val;
        dfs(root, null);
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(start, 0));
        boolean[] v = new boolean[501];
        v[start.val] = true;
        List<Integer> res = new LinkedList<>();
        while (!q.isEmpty()) {
            Node poll = q.poll();
            int dis = poll.dis;
            if (dis == K) {
                res.add(poll.treeNode.val);
                continue;
            }
            TreeNode p = parent.get(poll.treeNode);
            if (p != null && !v[p.val]) {
                q.add(new Node(p, dis + 1));
                v[p.val] = true;
            }

            if (poll.treeNode.left != null && !v[poll.treeNode.left.val]) {
                q.add(new Node(poll.treeNode.left, dis + 1));
                v[poll.treeNode.left.val] = true;
            }

            if (poll.treeNode.right != null && !v[poll.treeNode.right.val]) {
                q.add(new Node(poll.treeNode.right, dis + 1));
                v[poll.treeNode.right.val] = true;
            }
        }
        return res;
    }

    private void dfs(TreeNode root, TreeNode p) {
        if (root == null) return;
        if (root.val == t) {
            start = root;
        }
        parent.put(root, p);
        dfs(root.left, root);
        dfs(root.right, root);
    }

    class Node {
        public Node(TreeNode treeNode, int dis) {
            this.treeNode = treeNode;
            this.dis = dis;
        }

        TreeNode treeNode;
        int dis;
    }
}
