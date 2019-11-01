package com.dezhonger.y2019.m11.l1237;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/11/01
 *
 * @author dezhonger
 * @since 2019/11/01
 */
public class Leetcode1237 {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 1; i <= 1000; i++) {
            for (int j = 1; j <= 1000; j++) {
                if (customfunction.f(i, j) == z) {
                    List<Integer> list = new ArrayList<>();
                    list.add(i);
                    list.add(j);
                    res.add(list);
                }
            }
        }
        return res;
    }
}
