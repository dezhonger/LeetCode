package com.y2019.m10;

/**
 * Created by zhangweilong on 2019/10/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/10/11
 */
public class Leetcode1207 {
    public boolean uniqueOccurrences(int[] arr) {
        int[] c = new int[3000];
        int[] d = new int[3000];
        for (int x : arr) c[x + 1000]++;
        for (int x : c) if (x > 0) d[x]++;
        for (int i = 1; i < d.length; i++) {
            if (d[i] > 1) return false;
        }
        return true;
    }
}
