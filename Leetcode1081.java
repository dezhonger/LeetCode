package com.netease.music.leetcode;

import java.util.Stack;

/**
 * Created by dezhonger on 2019/6/15
 */
public class Leetcode1081 {
    public String smallestSubsequence(String text) {
        Stack<Integer> stack = new Stack<>();
        int[] lastIndex = new int[26];
        int[] v = new int[26];
        for (int i = 0; i < text.length(); i++) {
            lastIndex[text.charAt(i) - 'a'] = i;
        }
        for (int i = 0; i < text.length(); i++) {
            while (!stack.isEmpty() && v[text.charAt(i) - 'a'] == 0 && text.charAt(i) < text.charAt(stack.peek()) && lastIndex[text.charAt(stack.peek()) - 'a'] > i) {
                v[text.charAt(stack.peek()) - 'a'] = 0;
                stack.pop();
            }
            if (v[text.charAt(i) - 'a'] == 0) {
                stack.push(i);
                v[text.charAt(i) - 'a'] = 1;
            }

        }
        StringBuilder sb = new StringBuilder();
        while (!stack.empty()) {
            sb.append(text.charAt(stack.pop()));
        }
        return sb.reverse().toString();
    }
}
