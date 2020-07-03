package com.y2020.m07.d03;

import java.util.Stack;

/**
 * Created by zhangweilong on 2020/07/03
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/07/03
 */
public class Leetcode1475 {
    public int[] finalPrices(int[] prices) {
        int len = prices.length;
        int[] res = new int[len];
        Stack<Integer> s = new Stack<>();
        for (int i = len - 1; i >= 0; i--) {
            while (!s.isEmpty() && prices[s.peek()] > prices[i]) s.pop();
            int c = 0;
            if (!s.isEmpty()) c = prices[s.peek()];
            res[i] = prices[i] - c;
            if (c != prices[i]) s.push(i);
        }
        return res;
    }
}
