package com.netease.music.leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2020/3/11
 */
public class Leetcode0952 {
    int[] fa, sz;
    int ans = 1;

    int find(int x) {
        if (fa[x] == x) return x;
        return find(fa[x]);
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;
        if (sz[fx] < sz[fy]) {
            fa[fx] = fy;
            sz[fy] += sz[fx];
            ans = Math.max(ans, sz[fy]);
        } else {
            fa[fy] = fx;
            sz[fx] += sz[fy];
            ans = Math.max(ans, sz[fx]);
        }
    }

    public int largestComponentSize(int[] A) {
        int len = A.length;
        fa = new int[len];
        sz = new int[len];
        int ma = -1;
        for (int i = 0; i < len; i++) {
            fa[i] = i;
            sz[i] = 1;
            ma = Math.max(A[i], ma);
        }
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < len; i++) {
            for (int j = 1; j * j <= A[i]; j++) {
                if (A[i] % j == 0) {
                    if (j != 1) {
                        Integer last = m.get(j);
                        if (last != null ) {
                            merge(last, i);
                        }
                        m.put(j, i);
                    }
                    int another = A[i] / j;
                    if (j != another) {
                        Integer last = m.get(another);
                        if (last != null) {
                            merge(last, i);
                        }
                        m.put(another, i);
                    }
                }
            }
        }

        return ans;
    }
}
