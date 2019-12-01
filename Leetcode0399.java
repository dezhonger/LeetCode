package com.y2019.m11.d30;

import com.google.common.collect.Lists;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * Created by zhangweilong on 2019/12/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/01
 */
public class Leetcode0399 {
    Map<String, Integer> map = new HashMap<>();
    int index = 0;

    private int getIndex(String s) {
        Integer val = map.get(s);
        if (val == null) {
            map.put(s, index++);
            return index - 1;
        } else return val;
    }

    public static void main(String[] args) {
        Leetcode0399 sol = new Leetcode0399();
        List<List<String>> equations = new ArrayList<>();
        equations.add(Lists.newArrayList("a", "b"));
        equations.add(Lists.newArrayList("b", "c"));
        double[] values = new double[]{2.0, 3.0};
        List<List<String>> queries = new ArrayList<>();
        queries.add(Lists.newArrayList("a", "c"));
        queries.add(Lists.newArrayList("b", "a"));
        queries.add(Lists.newArrayList("a", "e"));
        queries.add(Lists.newArrayList("a", "a"));
        queries.add(Lists.newArrayList("x", "x"));
        sol.calcEquation(equations, values, queries);
    }

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        double[] res = new double[queries.size()];
        int maIndex = 0;
        Set<String> set = new HashSet<>();

        for (int i = 0; i < equations.size(); i++) {
            List<String> strings = equations.get(i);
            String a = strings.get(0);
            String b = strings.get(1);
            set.add(a);
            set.add(b);
        }
        int max = set.size();
        double[][] graph = new double[max][max];
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph.length; j++) {
                graph[i][j] = -1.0;
            }
        }

        for (int i = 0; i < equations.size(); i++) {
            List<String> strings = equations.get(i);
            String a = strings.get(0);
            int ai = getIndex(a);
            String b = strings.get(1);
            int bi = getIndex(b);
            graph[ai][ai] = 1;
            graph[bi][bi] = 1;
            graph[ai][bi] = values[i];
            graph[bi][ai] = 1.0 / values[i];
        }
        maIndex = index;

        for (int k = 0; k < maIndex; k++) {
            for (int i = 0; i < maIndex; i++) {
                for (int j = 0; j < maIndex; j++) {
                    if (graph[i][k] > 0 && graph[k][j] > 0) {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            List<String> strings = queries.get(i);
            Integer a = map.get(strings.get(0));
            Integer b = map.get(strings.get(1));
            if (a != null && b != null && a < maIndex && b < maIndex) {
                res[i] = graph[a][b];
            } else {
                res[i] = -1.0;
            }
        }
//        System.out.println(Arrays.toString(res));
        return res;
    }
}
