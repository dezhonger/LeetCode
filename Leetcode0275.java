package com.y2019.m11.d30;

/**
 * Created by zhangweilong on 2019/11/30
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/11/30
 */
public class Leetcode0275 {
    public int hIndex(int[] citations) {
        if (citations == null || citations.length == 0) {
            return 0;
        }
        int res = 0;
        for (int i = citations.length - 1, j = 1; i >= 0; i--, j++, res++) {
            if (citations[i] < j) break;
        }
        return res;
    }
}
