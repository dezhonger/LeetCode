package com.netease.music.leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2019/6/3
 */
public class Leetcode1074 {
    public int numSubmatrixSumTarget(int[][] a, int target) {
        int n = a.length;
        int m = a[0].length;
        int[][] cum = new int[n + 1][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cum[i + 1][j + 1] = cum[i + 1][j] + cum[i][j + 1] - cum[i][j] + a[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                Map<Integer, Integer> map = new HashMap<>();
                for (int k = 0; k <= m; k++) {
                    int v = cum[j + 1][k] - cum[i][k];
                    if (map.containsKey(v - target)) {
                        ans += map.get(v - target);
                    }
                    if (map.containsKey(v)) {
                        map.put(v, map.get(v) + 1);
                    } else {
                        map.put(v, 1);
                    }
                }
            }
        }
        return ans;
    }
}
