package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/4/8
 * <p>
 * 并查集
 */
public class Leetcode0990 {

    public static void main(String[] args) {
        Leetcode0990 code = new Leetcode0990();
        System.out.println(code.equationsPossible(new String[]{"a==b","b!=a"}));
        System.out.println(code.equationsPossible(new String[]{"b==a","a==b"}));
        System.out.println(code.equationsPossible(new String[]{"a==b","b==c","a==c"}));
        System.out.println(code.equationsPossible(new String[]{"a==b","b!=c","c==a"}));
        System.out.println(code.equationsPossible(new String[]{"c==c","b==d","x!=z"}));
        System.out.println(code.equationsPossible(new String[]{"c==c", "f!=a", "f==b", "b==c"}));
    }


    int[] father = new int[26];

    int find(int x) {
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }

    void merge(int x, int y) {
        father[y] = x;
    }

    public boolean equationsPossible(String[] equations) {

        for (int i = 0; i < father.length; i++) father[i] = i;
        List<String> s1 = new ArrayList<>();
        List<String> s2 = new ArrayList<>();
        for(String s : equations) {
            if (s.charAt(1) == '=') s1.add(s);
            else s2.add(s);
        }
        for (String s : s1) {
            char a = s.charAt(0);
            char b = s.charAt(s.length() - 1);
            int x = find(a - 'a');
            int y = find(b - 'a');
            if (x != y) merge(x, y);
        }
        for (String s : s2) {
            char a = s.charAt(0);
            char b = s.charAt(s.length() - 1);
            int x = find(a - 'a');
            int y = find(b - 'a');
            if (x == y) return false;
        }

        return true;
    }
}
