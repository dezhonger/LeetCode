package com.netease.music.leetcode;

import java.util.Stack;

/**
 * Created by dezhonger on 2019/5/23
 */
public class Leetcode0946 {
    public static void main(String[] args) {
        boolean x = new Leetcode0946().validateStackSequences(new int[]{1, 2, 3, 4, 5}, new int[]{4, 5, 3, 2, 1});
        System.out.println(x);
    }

    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int len = pushed.length;
        if (len != popped.length) return false;
        Stack<Integer> stack = new Stack<>();
        int c = 0;
        int index1 = 0;
        int index2 = 0;
        while (c < len) {
            while (stack.isEmpty() || stack.peek() != popped[index2]) {
                if (index1 < len) stack.push(pushed[index1++]);
                else return false;
            }
            if (stack.peek() == popped[index2]) {
                stack.pop();
                index2++;
                c++;
            } else {
                return false;
            }

        }
        return true;
    }
}
