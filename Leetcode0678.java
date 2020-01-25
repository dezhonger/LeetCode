package com.dezhonger.y2020.m01.d25;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Created by dezhonger on 2020/01/25
 *
 * @author dezhonger
 * @since 2020/01/25
 */
public class Leetcode0678 {
    public boolean checkValidString(String s) {
        int l, r, x;
        l = r = x = 0;
        //0:(  1:)  2:*
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(') {
                l++;
                stack.add(0);
            } else if (ch == ')') {
                if (l > 0) {
                    l--;
                    //pop出一个(
                    //eg: 处理(*)这种
                    List<Integer> tmp = new ArrayList<>();
                    while (stack.peek() != 0) {
                        tmp.add(stack.pop());
                    }
                    stack.pop();
                    for (int k = tmp.size() - 1; k >= 0; k--) stack.add(tmp.get(k));
                } else if (x > 0) {
                    x--;
                    //pop的是个*
                    stack.pop();
                } else return false;
            } else {
                x++;
                stack.add(2);
            }
        }
        int n = 0;
        while (!stack.empty()) {
            Integer pop = stack.pop();
            if (pop == 2) n++;
            else {
                //pop==0:(
                if (n > 0) n--;
                else return false;
            }
        }

        return true;
    }

}
