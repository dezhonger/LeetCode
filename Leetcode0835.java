package com.y2020.m01.d11;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by zhangweilong on 2020/01/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/11
 */
public class Leetcode0835 {
    public int largestOverlap(int[][] A, int[][] B) {
        int m = A.length;
        int n = A[0].length;
        int res = 0;
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) a.add(i * 100 + j);
            if (B[i][j] == 1) b.add(i * 100 + j);
        }
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : a) for (int y : b) map.put(x - y, map.getOrDefault(x - y, 0) + 1);
        for (int x : map.values()) res = Math.max(res, x);
        return res;
    }
}
