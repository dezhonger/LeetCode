package com.y2020.m05.d10;

import com.y2018.m11.d09.S;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangweilong on 2020/05/10
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/05/10
 */
public class Leetcode1441 {
    public List<String> buildArray(int[] target, int n) {
        List<String> res = new ArrayList<>();
        String[] op = new String[]{"Push", "Pop"};
        int cur = 1;
        for (int i = 0; i < target.length;) {
            if (target[i] == cur) {
                res.add(op[0]);
                i++;
            } else {
                res.add(op[0]);
                res.add(op[1]);
            }
            cur++;
        }
        return res;
    }
}
