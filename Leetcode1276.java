package com.y2019.m12.d01;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangweilong on 2019/12/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/01
 */
public class Leetcode1276 {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        List<Integer> res = new ArrayList<>();
        if (tomatoSlices % 2 == 1) return res;
        int x = tomatoSlices / 2 - cheeseSlices;
        int y = cheeseSlices - x;
        if (x >= 0 && y >= 0) {
            res.add(x);
            res.add(y);
            return res;
        }
        return res;
    }
}
