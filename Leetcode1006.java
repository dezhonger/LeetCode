package com.netease.music.leetcode;

import java.util.Stack;

/**
 * Created by dezhonger on 2019/4/1
 */
public class Leetcode1006 {

    public static void main(String[] args) {
        Leetcode1006 code = new Leetcode1006();
        System.out.println(code.clumsy(4));
        System.out.println(code.clumsy(4, false));
        System.out.println(code.clumsy(12));
        System.out.println(code.clumsy(12, false));
    }


    public int clumsy(int N) {
        Stack<Integer> stack = new Stack<>();
        char[] op = new char[]{'*', '/', '+', '-'};
        stack.push(N--);
        int index = 0;
        while (N > 0) {
            if (op[index] == '*') {
                stack.push(stack.pop() * N--);
            } else if (op[index] == '/') {
                stack.push(stack.pop() / N--);
            } else if (op[index] == '+') {
                stack.push(N--);
            } else if (op[index] == '-') {
                stack.push(-1 * (N--));
            }
            index = (index + 1) % 4;
        }
        int sum = 0;
        while (!stack.isEmpty()) {
            sum += stack.pop();
        }
        return sum;
    }


    int clumsy(int N, boolean inverse) {
        if (N >= 4 && !inverse) return N * (N - 1) / (N - 2) + (N - 3) - clumsy(N - 4, !inverse);
        else if (N >= 4 && inverse) return N * (N - 1) / (N - 2) - (N - 3) + clumsy(N - 4, inverse);
        else if (N == 3) return 3 * 2 / 1;
        else if (N == 2) return 2 * 1;
        else if (N == 1) return 1;
        return 0;
    }


}
