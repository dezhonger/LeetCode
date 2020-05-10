package com.y2020.m05.d10;

import org.apache.commons.compress.utils.Lists;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zhangweilong on 2020/05/10
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/05/10
 */
public class Leetcode1443 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1443().minTime(7, new int[][]{
                {0,1},
                {0,2},
                {1,4},
                {1,5},
                {2,3}, {2,6},
        }, Arrays.asList(false,false,true,false,true,true,false)));
    }

    List<List<Integer>> g;
    //子树有多少个苹果，不包含自己
    int[] has;
    List<Boolean> p;
    int ans = 0;
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        g = new ArrayList<>();
        for (int i = 0; i < n; ++i) g.add(new ArrayList<>());

        has = new int[n];
        this.p = hasApple;
        for (int[] x : edges) {
            List<Integer> g1 = g.get(x[0]);
            g1.add(x[1]);
            List<Integer> g2 = g.get(x[1]);
            g2.add(x[0]);
        }

        dfs1(0, -1);
        dfs2(0, -1);
        return ans - 2;
    }


    private int dfs1(int node, int pa) {
        for (int nxt : g.get(node)) {
            if (nxt == pa) continue;
            has[node] += dfs1(nxt, node);
        }
        if (p.get(node))  has[node]++;
        return has[node];
    }

    private void dfs2(int node, int pa) {
        ans+= 2;
        for (int nxt :g.get(node)) {
            if (nxt == pa) continue;
            if (has[nxt] == 0) continue;
            dfs2(nxt, node);
        }
    }

}
