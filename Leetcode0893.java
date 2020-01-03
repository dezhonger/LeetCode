package com.y2020.m03;

import org.apache.commons.collections4.multimap.HashSetValuedHashMap;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

/**
 * Created by zhangweilong on 2020/01/03
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/03
 */
public class Leetcode0893 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0893().numSpecialEquivGroups(new String[]{"abcd","cdab","cbad","xyzz","zzxy","zzyx"}));
    }
    public int numSpecialEquivGroups(String[] A) {
        Set<String> set = new HashSet<>();
        for (String s : A) {
            set.add(hash(s));
        }
        return set.size();
    }

    String hash(String s) {
        int len = s.length();
        int[] even = new int[26];
        int[] odd = new int[26];
        for (int i = 0; i < len; i += 2) {
            even[s.charAt(i) - 'a']++;
        }
        for (int i = 1; i < len; i += 2) {
            odd[s.charAt(i) - 'a']++;
        }
        return Arrays.toString(even) + Arrays.toString(odd);
    }

}
