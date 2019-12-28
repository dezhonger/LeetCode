package com.y2019.m12.d28;

import com.y2018.m11.d09.S;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 * Created by zhangweilong on 2019/12/28
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/28
 */
public class Leetcode1233_1 {
    List<String> res = new LinkedList<>();

    public static void main(String[] args) {
        Leetcode1233_1 sol = new Leetcode1233_1();
        //expected answer: ["/a","/c/d","/c/f"]
        System.out.println(sol.removeSubfolders(new String[]{
                "/a", "/a/b", "/c/d", "/c/d/e", "/c/f"
        }));
    }

    public List<String> removeSubfolders(String[] folder) {
        Trie root = new Trie();
        for (String str : folder) insert(root, str);
        dfs(root);
        return res;
    }

    private void dfs(Trie root) {
        if (root == null) return;
        for (Trie node : root.sons) {
            if (node.isEnd) {
                //不要再递归它的子目录了
                res.add(node.allVal);
            } else {
                dfs(node);
            }
        }
    }

    private void insert(Trie root, String str) {
        String[] split = str.split("/");
        StringBuilder sb = new StringBuilder();
        for (String s : split) {
            //
            if (s.length() == 0) continue;
            sb.append("/");
            sb.append(s);
            if (root.map.containsKey(s)) {
                root = root.sons.get(root.map.get(s));
            } else {
                root.sons.add(new Trie(s, sb.toString()));
                root.map.put(s, root.sons.size() - 1);
                root = root.sons.get(root.sons.size() - 1);
            }
        }
        root.isEnd = true;
    }

    class Trie {
        String val;
        String allVal;
        List<Trie> sons;
        Map<String, Integer> map;
        boolean isEnd;

        public Trie(String val, String allVal) {
            this.val = val;
            this.allVal = allVal;
            sons = new ArrayList<>();
            map = new HashMap<>();
            isEnd = false;
        }

        public Trie() {
            sons = new ArrayList<>();
            map = new HashMap<>();
            isEnd = false;
        }
    }

}
