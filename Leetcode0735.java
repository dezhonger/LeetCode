package com.y2019.m12.d05;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2019/12/05
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/05
 */
public class Leetcode0735 {
    public int[] dailyTemperatures(int[] T) {
        int[] res = new int[T.length];
        Arrays.fill(res, Integer.MAX_VALUE);
        res[T.length - 1] = 0;
        int[] v = new int[101];
        v[T[T.length - 1]] = T.length - 1;
        for (int i = T.length - 2; i >= 0; i--) {
            int x = T[i];
            for (int j = x + 1; j <= 100; j++) {
                if (v[j] > 0) res[i] = Math.min(v[j] - i, res[i]);
            }
            if (res[i] == Integer.MAX_VALUE) res[i] = 0;
            v[x] = i;
        }
        return res;
    }
}
