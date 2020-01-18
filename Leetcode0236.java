package com.dezhonger.y2020.m01.d19;

import com.dezhonger.y2019.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2020/01/19
 *
 * @author dezhonger
 * @since 2020/01/19
 */
public class Leetcode0236 {
    List<TreeNode> l = new ArrayList<>();
    List<TreeNode> r = new ArrayList<>();
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        dfs(root, p, l);
        dfs(root, q, r);
        int i = 0, j = 0;
        int ii = l.size() - i - 1;
        int jj = r.size() - i - 1;
        while (i < l.size() && j < r.size()) {
            if (ii > jj) {
                i++;
                ii--;
            } else if (ii < jj) {
                j++;
                jj--;
            } else {
                if (l.get(i).val == r.get(j).val) return l.get(i);
                else {
                    i++;
                    j++;
                    ii--;
                    jj--;
                }
            }
        }
        //cannot reach here
        return null;
    }

    private boolean dfs(TreeNode root, TreeNode p, List<TreeNode> list) {
        if (root == null) return false;
        if (root.val == p.val) {
            list.add(root);
            return true;
        }
        boolean a = dfs(root.left, p, list);
        boolean b = dfs(root.right, p, list);
        if (a || b) list.add(root);
        return a || b;
    }

}
