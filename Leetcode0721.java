package com.dezhonger.y2020.m01.d15;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

/**
 * Created by dezhonger on 2020/01/15
 *
 * @author dezhonger
 * @since 2020/01/15
 */
public class Leetcode0721 {
    int[] f;

    int find(int x) {
        int fx = f[x];
        if (fx == x) return x;
        return f[x] = find(fx);
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) f[fx] = fy;
    }

    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int len = accounts.size();
        f = new int[len];

        for (int i = 0; i < len; i++) f[i] = i;

        for (int i = 0; i < len; i++) {
            List<String> ai = accounts.get(i);
            String namei = ai.get(0);
            for (int j = i + 1; j < len; j++) {
                List<String> aj = accounts.get(j);
                String namej = aj.get(0);
                if (!namei.equals(namej)) continue;
                if (check(ai, aj)) {
                    merge(i, j);
                }
            }
        }
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < len; i++) {
            int fx = find(i);
            List<Integer> orDefault = map.getOrDefault(fx, new ArrayList<>());
            orDefault.add(i);
            map.put(fx, orDefault);
        }


        List<List<String>> res = new ArrayList<>();
        for (List<Integer> l : map.values()) {
            String name = accounts.get(l.get(0)).get(0);
            Set<String> tmp = new TreeSet<>();
            for (int x : l) {
                List<String> strings = accounts.get(x);
                for (int k = 1; k < strings.size(); k++) tmp.add(strings.get(k));
            }
            List<String> r = new LinkedList<>();
            r.add(name);
            r.addAll(tmp);
            res.add(r);
        }
        return res;
    }

    private boolean check(List<String> ai, List<String> aj) {
        for (int i = 1; i < ai.size(); i++) {
            for (int j = 0; j < aj.size(); j++) {
                if (ai.get(i).equals(aj.get(j))) {
                    return true;
                }
            }
        }
        return false;
    }
}
