package com.netease.music.leetcode;

import java.util.Arrays;
import java.util.Stack;

/**
 * Created by dezhonger on 2019/7/10
 *
 * 单调栈
 */
public class Leetcode0907 {

    public static void main(String[] args) {
//        new Leetcode0907().sumSubarrayMins(new int[]{3, 1, 2, 4});
        new Leetcode0907().sumSubarrayMins(new int[]{71,55,82,55});
    }
    int len;
    int[] a1;
    int[] a2;
    int[] a3;

    public int sumSubarrayMins(int[] A) {
        len = A.length;
        a1 = new int[len];
        a2 = new int[len];
        a3 = new int[len];
        cal1(A, a1);

        int[] B = new int[len];
        for (int i = len - 1; i >=0 ;i--) B[len - i - 1] = A[i];
        //B:{4,2,1,3}
        cal2(B, a2);
        for (int i = len - 1; i >=0 ;i--) a3[len - i - 1] = a2[i];
        int res = 0;
        for (int i = 0; i < len ;i++) {
            res += A[i] * a1[i] * a3[i];
            res %= 10_0000_0007;
        }
        System.out.println(res);
        return res;
    }

    void cal1(int[] A, int[] a) {
        Stack<Integer> stack = new Stack<>();
        Arrays.fill(a, -1);
        for (int i = 0; i < len; i++) {
            while (!stack.empty() && A[stack.peek()] >= A[i]) {
                int t = stack.pop();
                a[t] = i;
            }
            stack.push(i);
        }
        for (int i = 0; i < len; i++) {
            if (a[i] == -1) a[i] = len - i;
            else a[i] = a[i] - i;

        }
    }

    void cal2(int[] A, int[] a) {
        Stack<Integer> stack = new Stack<>();
        Arrays.fill(a, -1);
        for (int i = 0; i < len; i++) {
            while (!stack.empty() && A[stack.peek()] > A[i]) {
                int t = stack.pop();
                a[t] = i;
            }
            stack.push(i);
        }
        for (int i = 0; i < len; i++) {
            if (a[i] == -1) a[i] = len - i;
            else a[i] = a[i] - i;

        }
    }

}
