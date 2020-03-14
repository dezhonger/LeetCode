package com.netease.music.leetcode;

import java.util.Timer;

/**
 * Created by dezhonger on 2020/3/14
 */
public class Leetcode0517 {
    public int findMinMoves(int[] machines) {
        int sum = 0;
        int len = machines.length;
        for (int i = 0; i < len; i++) sum += machines[i];
        if (sum % len != 0) return -1;
        int avg = sum / len;
        int preSum = 0;
        int result = 0;
        for (int i = 0; i < machines.length; i++) {
            int suffixSum = sum - preSum - machines[i];
            int left = preSum - avg * i;
            int right = suffixSum - avg * (len - i - 1);
            if (left >= 0 && right >= 0) result = Math.max(result, Math.max(left, right));
            else if (left < 0 && right < 0) result = Math.max(result, -(left + right));
            else result = Math.max(result, Math.max(result, Math.max(Math.abs(left), Math.abs(right))));
            preSum += machines[i];
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(new Leetcode0517().findMinMoves(new int[]{1,0,5}));
        System.out.println(new Leetcode0517().findMinMoves(new int[]{0,3,0}));
        System.out.println(new Leetcode0517().findMinMoves(new int[]{4,0,0,4}));
    }
}
