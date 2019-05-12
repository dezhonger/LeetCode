package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

/**
 * Created by dezhonger on 2019/5/12
 */
public class Leetcode1042 {
    public int[] gardenNoAdj(int N, int[][] paths) {
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < N; i++) g.add(new ArrayList<>());
        for (int i = 0; i < paths.length; i++) {
            int from = paths[i][0];
            int to = paths[i][1];
            from--;to--;
            g.get(from).add(to);
            g.get(to).add(from);
        }

        int[] res = new int[N];
        for (int i = 0; i < N; i++) {
            List<Integer> gl = g.get(i);
            boolean[] tmp = new boolean[5];
            for (int x : gl) {
                if (res[x] > 0) tmp[res[x]] = true;
            }
            int result = 0;
            for (int k = 1; k <= 4; k++) {
                if (!tmp[k]) {
                    result = k;
                    break;
                }
            }
            res[i] = result;
        }
        return res;
    }
}
