package com.dezhonger.y2019.m07.d12;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/07/12
 *
 * @author dezhonger
 * @since 2019/07/12
 */
public class Leetcode0830 {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<Integer> list = new ArrayList<>();
        list.add(0);
        for (int i = 1; i < S.length(); i++) {
            if (S.charAt(i) != S.charAt(i - 1)) {
                list.add(i);
            }
        }
        list.add(S.length());

        List<List<Integer>> r = new ArrayList<>();
        for (int i = 0; i < list.size() - 1; i++) {
            int s = list.get(i);
            int t = list.get(i + 1);
            int size = t - s;
            if (size >= 3) {
                List<Integer> tmp = new ArrayList<>();
                tmp.add(s);
                tmp.add(t - 1);
                r.add(tmp);
            }
        }
        return r;
    }
}
