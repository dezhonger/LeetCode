package com.y2019.m12.d27;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by zhangweilong on 2019/12/27
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/27
 */
public class Leetcode0720 {

    public String longestWord(String[] words) {
        Arrays.sort(words, String::compareTo);
        Set<String> set = new HashSet<>();
        String res = "";
        for (String s : words) {
            if (s.length() == 1 || set.contains(s.substring(0, s.length() - 1))) {
                if (s.length() > res.length()) res = s;
                set.add(s);
            }
        }
        return res;
    }
}
