package com.dezhonger.y2020.m01.d09;

import com.dezhonger.y2019.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by dezhonger on 2020/01/09
 *
 * @author dezhonger
 * @since 2020/01/09
 *
 * LEETCODE 919
 */
public class CBTInserter {
    TreeNode root;
    Queue<TreeNode> q;
    Queue<TreeNode> q2;

    public CBTInserter(TreeNode root) {
        this.root = root;
        q = new LinkedList<>();
        q2 = new LinkedList<>();
        q2.add(root);
        while (!q2.isEmpty()) {
            TreeNode poll = q2.poll();
            q.add(poll);
            if (poll.left != null) q2.add(poll.left);
            if (poll.right != null) q2.add(poll.right);
        }
    }

    public int insert(int v) {
        while (!q.isEmpty()) {
            TreeNode poll = q.peek();
            if (poll.left != null && poll.right != null) {
                q.poll();
            } else if (poll.left == null) {
                TreeNode l = new TreeNode(v);
                poll.left = l;
                q.add(l);
                return poll.val;
            } else if (poll.right == null) {
                TreeNode r = new TreeNode(v);
                poll.right = r;
                q.poll();
                q.add(r);
                return poll.val;
            } else {
                //cannot reach here
            }
        }
        return -1;
    }

    public TreeNode get_root() {
        return root;
    }
}
