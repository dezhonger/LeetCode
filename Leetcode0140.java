package com.netease.music.p20200228;


import com.google.common.collect.Lists;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * Created by dezhonger on 2020/2/28
 */
public class Leetcode0140 {
    Set<String> set = new HashSet<>();
    Map<String, List<String>> mp = new HashMap<>();
    int mi = Integer.MAX_VALUE, ma = Integer.MIN_VALUE;

    public static void main(String[] args) {
        Leetcode0140 sol = new Leetcode0140();
        System.out.println(sol.wordBreak("catsanddog", Lists.newArrayList("cat", "cats", "and", "sand", "dog")));
        System.out.println(sol.wordBreak("pineapplepenapple", Lists.newArrayList("apple", "pen", "applepen", "pine", "pineapple")));
    }

    public List<String> wordBreak(String s, List<String> wordDict) {
        for (String str : wordDict) {
            set.add(str);
            mi = Math.min(mi, str.length());
            ma = Math.max(ma, str.length());
        }
        dfs(s);
        return mp.get(s);
    }

    private List<String> dfs(String s) {
        if (mp.containsKey(s)) return mp.get(s);

        LinkedList<String> res = new LinkedList<>();
        if (s.length() == 0) {
            return Arrays.asList("");
        }

        for (int i = mi; i <= Math.min(ma, s.length()); i++) {
            String str = s.substring(0, i);
            int len = str.length();
            if (set.contains(str)) {
                List<String> list = dfs(s.substring(i));
                if (list.size() == 0) continue;
                for (String t : list) {
                    String ss = str + (t.equals("") ? "" : " ") + t;
                    res.add(ss);
                }
            }
        }
        mp.put(s, res);
        return res;
    }
}
