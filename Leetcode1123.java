package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * Created by dezhonger on 2019/7/14
 */
public class Leetcode1123 {

    List<Node> nodes = new ArrayList<>();
    int maxDepth = -1;

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        dfs(root, null, 0);
        Map<Integer, List<Node>> map =nodes.stream().collect(Collectors.groupingBy(Node::getDepth));
        List<Node> nodes = map.get(maxDepth);
         while (nodes.size() > 1) {
             Set<Node> set = new HashSet<>();
             for (Node node : nodes) {
                 set.add(node.parent);
             }
             nodes = new ArrayList<>(set);
         }
        return nodes.get(0).it;

    }

    private void dfs(TreeNode root, Node parent, int depth) {
        if (root == null) return;
        maxDepth = Math.max(maxDepth, depth);
        Node node = new Node(root, parent, depth);
        nodes.add(node);
        dfs(root.left, node, depth + 1);
        dfs(root.right, node, depth + 1);

    }


    class Node {
        public int getDepth() {
            return depth;
        }

        public Node(TreeNode it, Node parent, int depth) {
            this.it = it;
            this.parent = parent;
            this.depth = depth;
        }

        TreeNode it;
        Node parent;
        int depth;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Node node = (Node) o;
            return Objects.equals(it, node.it);
        }

        @Override
        public int hashCode() {
            return Objects.hash(it);
        }
    }
}
