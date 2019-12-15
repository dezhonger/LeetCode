package com.y2019.m12.d15;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by zhangweilong on 2019/12/15
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/15
 */
public class Leetcode1291 {

    List<Integer> list = new ArrayList<>();

    public List<Integer> sequentialDigits(int low, int high) {
        init();
        List<Integer> res = new LinkedList<>();
        for (int x : list) {
            if (low <= x && x <= high) res.add(x);
        }
        return res;
    }

    //    10 <= low <= high <= 10^9
    void init() {
        String str = "123456789";
        for (int i = 2; i <= str.length(); i++) {
            for (int j = 0; j < str.length() - i + 1; j++) {
                list.add(Integer.parseInt(str.substring(j, j + i)));
            }
        }
    }
}
