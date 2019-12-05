package com.y2019.m12.d05;

import java.util.Stack;

/**
 * Created by zhangweilong on 2019/12/05
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/05
 */
public class Leetcode0856 {
    public int scoreOfParentheses(String S) {
        int res = 0;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '(') {
                stack.push(-1);
            } else {
                if (stack.peek() == -1) {
                    stack.pop();
                    stack.push(1);
                } else {
                    int tmp = 0;
                    while (stack.peek() != -1) {
                        tmp += stack.pop();
                    }
                    stack.pop();
                    stack.push(tmp * 2);
                }
            }
        }
        while (!stack.empty()) {
            res += stack.pop();
        }
        return res;
    }
}
