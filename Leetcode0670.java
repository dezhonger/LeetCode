package com.y2019.m12.d16;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by zhangweilong on 2019/12/16
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/16
 */
public class Leetcode0670 {
    public int maximumSwap(int num) {
        if (num <= 10) return num;
        List<Integer> list = new ArrayList<>();
        int x = num;
        while (x > 0) {
            list.add(x % 10);
            x /= 10;
        }
        Collections.reverse(list);
        Integer[] ts = list.toArray(new Integer[list.size()]);
        boolean f = false;
        for (int i = 0; i < ts.length - 1; i++) {
            if (ts[i] < ts[i + 1]) {
                f = true;
                break;
            }
        }
        if (!f) {
            return num;
        }

        for (int i = 0; i < ts.length; i++) {
            int ma = ts[i];
            int index = -1;
            boolean find = false;
            for (int j = i + 1; j < ts.length; j++) {
                if (ts[j] > ma || (find && ts[j] >= ma)) {
                    ma = ts[j];
                    index = j;
                    find = true;
                }
            }
            if (index != -1) {
                int tmp = ts[i];
                ts[i] = ts[index];
                ts[index] = tmp;
                break;
            }

        }
        int res = 0;
        for (int a : ts) res = res * 10 + a;
        return res;
    }
}
