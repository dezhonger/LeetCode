package com.y2020.m01.d11;

/**
 * Created by zhangweilong on 2020/01/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/11
 */
public class Leetcode0785 {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        for (int i = 0; i < n ;i++) {
            if (color[i] == 0) {
                color[i] = 1;
                if (!dfs(color, i, 1, graph)) return false;
            }
        }
        return true;
    }

    private boolean dfs(int[] color, int i, int c, int[][] graph) {
        for (int nxt : graph[i]) {
            if (color[nxt] == c) return false;
            if (color[nxt] == 0) {
                color[nxt] = 3 - c;
                if (!dfs(color, nxt, 3 - c, graph)) return false;
            }
        }
        return true;
    }

}
