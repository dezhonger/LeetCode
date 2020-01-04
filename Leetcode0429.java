package com.netease.music.leetcode.p0429;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by dezhonger on 2020/1/4
 */
public class Leetcode0429 {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root == null) return res;
        dfs(root, res, 0);
        return res;
    }

    private void dfs(Node root, List<List<Integer>> res, int d) {
        if (root == null || root.children == null) return;
        if (res.size() < d + 1) res.add(new LinkedList<>());
        res.get(d).add(root.val);
        for (Node child : root.children) dfs(child, res, d + 1);
    }
}

class Node {
    public int val;
    public List<Node> children;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
}


