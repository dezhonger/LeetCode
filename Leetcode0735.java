package com.y2020.m01.d05;

import java.util.Stack;

/**
 * Created by zhangweilong on 2020/01/05
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/05
 */
public class Leetcode0735 {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();
        for (int x : asteroids) {
            if (stack.empty()) stack.add(x);
            else {
                while (true) {
                    if (!stack.empty() && x < 0 && stack.peek() > 0) {
                        if (-x == stack.peek()) {
                            stack.pop();
                            break;
                        }
                        else if (-x > stack.peek()) {
                            stack.pop();
                        } else {
                            break;
                        }
                    } else {
                        stack.add(x);
                        break;
                    }
                }

            }
        }
        if (stack.size() == 0) return new int[0];
        int[] res = new int[stack.size()];
        for (int i = res.length - 1; i >= 0; i--) res[i] = stack.pop();
        return res;
    }

}
