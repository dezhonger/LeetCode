package com.y2020.m01.d11;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by zhangweilong on 2020/01/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/11
 */
public class Leetcode0822 {
    public int flipgame(int[] fronts, int[] backs) {
        int res = Integer.MAX_VALUE;
        int len = fronts.length;
        boolean[] v = new boolean[2001];
        for (int i = 0; i < len; i++) {
            if (fronts[i] == backs[i]) v[fronts[i]] = true;
        }
        for (int x : fronts) if (!v[x]) res = Math.min(res, x);
        for (int x : backs) if (!v[x]) res = Math.min(res, x);
        if (res == Integer.MAX_VALUE) res = 0;
        return res;
    }
}
