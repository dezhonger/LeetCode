package com.netease.music.leetcode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2020/3/11
 */
public class Leetcode0854 {


    char[] c1;
    char[] c2;
    int len;
    Map<String, Integer> mp;


    public int kSimilarity(String A, String B) {

        c1 = A.toCharArray();
        c2 = B.toCharArray();
        len = c1.length;
        mp = new HashMap<>();
        return dfs(c1, c2, 0);
    }

    private int dfs(char[] a, char[] b, int index) {
        if (Arrays.equals(a, b)) return 0;
        if (mp.get(new String(a)) != null) return mp.get(new String(a));
        while (index < len && a[index] == b[index]) index++;
        int mi = Integer.MAX_VALUE;
        for (int j = index + 1; j < len; j++) {
            if (a[j] == b[index]) {
                swap(a, j, index);
                mi = Math.min(dfs(a, b, index + 1) + 1, mi);
                swap(a, j, index);
            }
        }
        mp.put(new String(a), mi);
        return mi;
    }


    void swap(char[] a, int x, int y) {
        char t = a[x];
        a[x] = a[y];
        a[y] = t;
    }


}
