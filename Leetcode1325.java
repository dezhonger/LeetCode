package com.dezhonger.y2020.m01.d19;

import com.dezhonger.y2019.TreeNode;

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;

/**
 * Created by dezhonger on 2020/01/20
 *
 * @author dezhonger
 * @since 2020/01/20
 */
public class Leetcode1325 {
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if (root == null) return null;
        Queue<Node> q = new ArrayDeque<>();
        q.add(new Node(root, null, -1));
        Stack<Node> stack = new Stack<>();
        while (!q.isEmpty()) {
            Node poll = q.poll();
            stack.add(poll);
            if (poll.v.left != null) {
                q.add(new Node(poll.v.left, poll.v, 0));
            }
            if (poll.v.right != null) {
                q.add(new Node(poll.v.right, poll.v, 1));
            }
        }
        
        while (!stack.empty()) {
            Node pop = stack.pop();
            if (pop.v.left == null && pop.v.right == null) {
                if (pop.v.val == target) {
                    if (pop.pos == 0) pop.p.left = null;
                    else if (pop.pos == 1) pop.p.right = null;
                    else {
                        //是root节点
                        return null;
                    }
                }
            }

        }
        return root;
    }

    static class Node {
        TreeNode v;
        TreeNode p;
        int pos;

        public Node(TreeNode v, TreeNode p, int pos) {
            this.v = v;
            this.p = p;
            this.pos = pos;
        }
    }
}
