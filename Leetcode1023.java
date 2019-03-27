package com.netease.music.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Created by dezhonger on 2019/3/26
 */

public class Leetcode1023 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1023().queryString("0110", 3));
        System.out.println(new Leetcode1023().queryString("0110", 4));
        System.out.println(new Leetcode1023().queryString("0110100100110010110101011001101100111101", 20));
        System.out.println(new Leetcode1023().queryString("1001001000100010000011110000110110000111001100010100110101001001100001", 35));
    }

    public boolean queryString(String S, int N) {
        Map<String, Long> map = new HashMap<>();
        Set<Long> set = new HashSet<>();
        int len = S.length();
        if (len * (len + 1) / 2 < N) return false;
        for (int i = 0; i < len ;i++) {
            if (S.charAt(i) == '0') continue;
            for (int j = i + 1; j <= Math.min(len, i + 32); j++) {
                String str = S.substring(i, j);
                if (map.get(str) == null) {
                    Long integer = Long.valueOf(str, 2);
                    if (integer <= N) set.add(integer);
                    map.put(str, integer);
                }
            }
        }
        return set.size() == N;
    }
}
