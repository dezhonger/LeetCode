package com.y2019.m12.d05;

import java.util.Arrays;
import java.util.Stack;

/**
 * Created by zhangweilong on 2019/12/05
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/05
 */
public class Leetcode0735_2 {
    public int[] dailyTemperatures(int[] T) {
        Stack<Integer> s = new Stack<>();

        int len = T.length;
        int[] res = new int[len];
        for(int i = len - 1; i >= 0; i--) {
            while(!s.isEmpty() && T[s.peek()] <= T[i]) {
                s.pop();
            }
            if(s.isEmpty()) res[i] = 0;
            else res[i] = s.peek() - i;
            s.push(i);
        }
        return res;
    }
}
