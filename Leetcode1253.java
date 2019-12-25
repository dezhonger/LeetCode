package com.y2019.m12.d25;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by zhangweilong on 2019/12/25
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/25
 */
public class Leetcode1253 {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        int sum = Arrays.stream(colsum).sum();
        List<List<Integer>> res = new ArrayList<>();
        if (upper + lower != sum) return res;
        List<Integer> r1 = new ArrayList<>();
        List<Integer> r2 = new ArrayList<>();
        for (int i = 0; i < colsum.length; i++) {
            if (colsum[i] == 0) {
                r1.add(0);
                r2.add(0);
            } else if (colsum[i] == 2) {
                r1.add(1);
                r2.add(1);
                if (upper <= 0) return res;
                if (lower <= 0) return res;
                upper--;
                lower--;
            } else {
                if (upper > lower) {
                    r1.add(1);
                    r2.add(0);
                    if (upper <= 0) return res;
                    upper--;
                } else {
                    r1.add(0);
                    r2.add(1);
                    if (lower <= 0) return res;
                    lower--;
                }
            }
        }
        res.add(r1);
        res.add(r2);
        return res;
    }
}
