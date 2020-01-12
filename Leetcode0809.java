package com.y2020.m01.d12;

import com.alibaba.druid.sql.visitor.functions.Char;
import com.y2018.m11.d09.S;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangweilong on 2020/01/12
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/12
 */
public class Leetcode0809 {
    public int expressiveWords(String S, String[] words) {
        int res = 0;
        int i = 0;
        int c = 0;
        List<Character> ch = new ArrayList<>();
        List<Integer> size = new ArrayList<>();
        while (i < S.length()) {
            c++;
            if (i == S.length() - 1 || S.charAt(i) != S.charAt(i + 1)) {
                ch.add(S.charAt(i));
                size.add(c);
                c = 0;
            }
            i++;
        }

        for (String s : words) {
            if (s.length() > S.length()) continue;

            int j = 0;
            int d = 0;
            int index = 0;
            boolean f = true;
            while (j < s.length() && f && index < ch.size()) {
                d++;
                if (j == s.length() - 1 || s.charAt(j) != s.charAt(j + 1)) {
                    if (s.charAt(j) != ch.get(index)) f = false;
                    int si = size.get(index);
                    if (si < d) f = false;
                    if (si != d && si < 3) f = false;
                    d = 0;
                    index++;
                }
                j++;
            }
            if (f && j == s.length() && index == ch.size()) res++;
        }
        return res;
    }
}
