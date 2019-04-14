package com.netease.music.leetcode.contest.no132;

/**
 * Created by dezhonger on 2019/4/14
 */
public class Leetcode1028 {
    int pos = 0;
    char[] s;
    int len = 0;

    public TreeNode recoverFromPreorder(String S) {
        len = S.length();
        s = S.toCharArray();
        pos = 0;
        return go(0);
    }

    TreeNode go(int dep) {
        int v = 0;
        while (pos < len && s[pos] >= '0' && s[pos] <= '9') {
            v = v * 10 + (s[pos] - '0');
            pos++;
        }
        TreeNode cur = new TreeNode(v);

        if (hasEdge(dep + 1)) {
            pos += dep + 1;
            cur.left = go(dep + 1);
        }
        if (hasEdge(dep + 1)) {
            pos += dep + 1;
            cur.right = go(dep + 1);
        }

        return cur;
    }

    boolean hasEdge(int d) {
        if (pos + d > len - 1) return false;
        for (int i = pos; i < pos + d; i++) {
            if (s[i] != '-') return false;
        }
        return s[pos + d] != '-';
    }
}
