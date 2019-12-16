package com.y2019.m12.d16;

import java.util.List;

/**
 * Created by zhangweilong on 2019/12/16
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/16
 */
public class Leetcode0814 {
    int c;
    int[] v;

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        v = new int[rooms.size()];
        c = 1;
        v[0] = 1;
        dfs(0, rooms);
        return c == v.length;
    }

    private void dfs(int a, List<List<Integer>> rooms) {
        List<Integer> integers = rooms.get(a);
        if (integers == null || integers.size() == 0) return;
        for (int x : integers) {
            if (v[x] == 0) {
                v[x] = 1;
                c++;
                dfs(x, rooms);
            }
        }
    }
}
