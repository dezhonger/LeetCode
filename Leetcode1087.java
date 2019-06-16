package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2019/6/16
 */
public class Leetcode1087 {
    public static void main(String[] args) {
//        new Leetcode1087().expand("{a,b}c{d,e}f");
        new Leetcode1087().expand("{a}{a}{a}");
    }
    public String[] expand(String S) {
        for (int i = 0; i < S.length();) {
            if (S.charAt(i) == '{') {
                List<String> list = new ArrayList<>();
                int st = i + 1;
                int j = i + 1;
                for (; j < S.length(); j++) {
                    if (S.charAt(j) =='}')break;
                }
                String[] str = S.substring(st, j).split(",");
                list.addAll(Arrays.asList(str));
                r.add(list);
                i = j + 1;
            } else {
                int j = i;
                StringBuilder sb = new StringBuilder();
                for (; j < S.length(); j++) {
                    if (S.charAt(j) == '{') break;
                    sb.append(S.charAt(j));
                }
                List<String> list = new ArrayList<>();
                list.add(sb.toString());
                r.add(list);
                i = j;

            }
        }


        dfs(0, "", r.size());
        Collections.sort(res);
        return res.toArray(new String[res.size()]);
    }

    List<String> res = new ArrayList<>();
    List<List<String>> r = new ArrayList<>();

    void dfs(int index, String tmp, int len) {
        if (index == len) {
            res.add(tmp);
            return;
        }
        List<String> strings = r.get(index);
        for (int i = 0; i < strings.size(); i++) {
            dfs(index + 1, tmp + strings.get(i), len);
        }
    }
}
