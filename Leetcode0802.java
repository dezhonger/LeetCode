package com.dezhonger.y2020.m01.d09;

import java.text.DateFormatSymbols;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2020/01/09
 *
 * @author dezhonger
 * @since 2020/01/09
 */
public class Leetcode0802 {
    int[] nodeState;
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> res = new ArrayList<>();
        nodeState = new int[graph.length];
        //0:unknown 1:访问中 2:safe 3:nusafe

        for (int i = 0; i < graph.length;i ++) {
            if (2 == dfs(graph, i)) res.add(i);
        }
        return res;
    }

    private int dfs(int[][] graph, int x) {
        if (nodeState[x] == 1) {
            return nodeState[x] = 3;
        }
        if (nodeState[x] == 1 || nodeState[x] == 2) {
            return nodeState[x];
        }
        nodeState[x] =1;
        for (int next : graph[x]) {
            if (dfs(graph, next) == 3) {
                return nodeState[x] = 3;
            }
        }
        return nodeState[x] = 2;
    }
}
