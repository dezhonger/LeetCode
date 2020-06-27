package com.y2020.m06.d27;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 * Created by zhangweilong on 2020/06/27
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/06/27
 */
public class Leetcode1488 {

    public int[] avoidFlood(int[] rains) {
        int len = rains.length;
        int[] res = new int[len];
        Map<Integer, Integer> s = new HashMap<>();
        boolean can = true;
        //存储rain[i] = 0的下标
        Deque<Integer> dq = new ArrayDeque<>();

        //记录被注水的时刻
        Map<Integer, Integer> add = new HashMap<>();
        for (int i = 0; i < len; i++) {
            if (rains[i] > 0) {
                res[i] = -1;
                int cur = s.getOrDefault(rains[i], 0);
                if (cur == 0) {
                    add.put(rains[i], i);
                }
                s.put(rains[i], cur + 1);
                if (s.getOrDefault(rains[i], 0) > 1) {
                    if (dq.isEmpty()) {
                        can = false;
                        break;
                    } else {
                        boolean f = false;
                        List<Integer> x = new LinkedList<>();
                        while (!dq.isEmpty()) {
                            int index = dq.pollFirst();

                            if (index > add.get(rains[i])) {
                                res[index] = rains[i];
                                s.put(rains[i], s.get(rains[i]) - 1);
                                add.put(rains[i], i);
                                f = true;
                                break;
                            }
                            x.add(index);
                        }
                        if (!f) {
                            can = false;
                            break;
                        } else {
                            for (int k = x.size() - 1; k >= 0; k--) dq.addFirst(x.get(k));

                        }
                    }
                }

            } else {
                dq.addLast(i);
            }
        }
        if (!can) {
            return new int[0];
        } else {
            while (!dq.isEmpty()) {
                res[dq.pollFirst()] = 1;
            }
            return res;
        }
    }
}
