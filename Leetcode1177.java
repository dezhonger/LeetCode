package com.y2019.m12.d27;

/**
 * Created by zhangweilong on 2019/12/27
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/27
 */
public class Leetcode1177 {
    public int equalSubstring(String s, String t, int maxCost) {
        int[] c = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            c[i] = Math.abs(s.charAt(i) - t.charAt(i));
        }
        int l = 0;
        int r = 0;
        int res = 0;
        int cost = 0;
        for (; r < s.length(); r++) {
            cost += c[r];
            while (cost > maxCost) {
                cost -= c[l++];
            }
            res = Math.max(res, r - l + 1);
        }
        return res;
    }
}
