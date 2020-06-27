package com.y2020.m06.d27;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by zhangweilong on 2020/06/27
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/06/27
 */
public class Leetcode1487 {
    public String[] getFolderNames(String[] names) {
        int len = names.length;
        String[] res = new String[len];
        Map<String, Integer> mp = new HashMap<>();

        for (int i = 0; i < len; i++) {
            if (!mp.containsKey(names[i])) {
                res[i] = names[i];
                mp.put(names[i], 0);
                res[i] = names[i];
            } else {
                int num = mp.getOrDefault(names[i], 0) + 1;
                while (true) {
                    String s = names[i] + "(" + num + ")";
                    if (!mp.containsKey(s)) {
                        mp.put(names[i], num);
                        mp.put(s, 0);
                        res[i] = s;
                        break;
                    } else {
                        num++;
                    }
                }
            }
        }
        return res;
    }
}
