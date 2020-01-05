package com.y2020.m01.d05;

import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Set;

/**
 * Created by zhangweilong on 2020/01/05
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/05
 */
public class Leetcode0966 {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> set = new LinkedHashSet<>(Arrays.asList(wordlist));
        Map<String, String> low = new HashMap<>();
        Map<String, String> deVowel = new HashMap<>();
        for (String s : set) {
            low.putIfAbsent(s.toLowerCase(), s);
            deVowel.putIfAbsent(s.toLowerCase().replaceAll("[aeiou]", "#"), s);
        }
        for (int i = 0; i < queries.length; i++) {
            if (set.contains(queries[i])) continue;
            if (low.containsKey(queries[i].toLowerCase())) queries[i] = low.get(queries[i].toLowerCase());
            else if (deVowel.containsKey(queries[i].toLowerCase().replaceAll("[aeiou]", "#"))) queries[i] = deVowel.get(queries[i].toLowerCase().replaceAll("[aeiou]", "#"));
            else queries[i] = "";
        }
        return queries;
    }
}
