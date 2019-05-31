package com.dezhonger.y2019.m06.d01;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by dezhonger on 2019/05/31
 *
 * @author dezhonger
 * @since 2019/05/31
 */
public class Leetcode0811 {
    class Solution {
        public List<String> subdomainVisits(String[] cpdomains) {
            Map<String, Integer> map = new HashMap<>();
            for (String string : cpdomains) {
                String[] sa = string.split(" ");
                String s = sa[1];
                int c = Integer.valueOf(sa[0]);
                int cnt = map.getOrDefault(s, 0);
                map.put(s, cnt + c);
                for (int i = 0; i < s.length();i ++) {
                    if (s.charAt(i) == '.') {
                        String str = s.substring(i + 1);
                        cnt = map.getOrDefault(str, 0);
                        map.put(str, cnt + c);
                    }
                }
            }
            List<String> r = new ArrayList<>();
            map.forEach((k, v) -> {
                r.add(v + " " + k);
            });
            return r;

        }
    }
}
