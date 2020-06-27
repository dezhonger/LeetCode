package com.y2020.m06.d27;

/**
 * Created by zhangweilong on 2020/06/27
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/06/27
 */
public class Leetcode1486 {
    public int xorOperation(int n, int start) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= (start + 2 * i);
        }
        return res;
    }
}
