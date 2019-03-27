package com.netease.music.leetcode;

/**
 * Created by dezhonger on 2019/3/26
 */
public class Leetcode1022 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1022().smallestRepunitDivByK(1));
        System.out.println(new Leetcode1022().smallestRepunitDivByK(2));
        System.out.println(new Leetcode1022().smallestRepunitDivByK(3));
    }

    public int smallestRepunitDivByK(int K) {
        int[] m = new int[K];
        int cur = 1;
        int res = 1;
        while(true) {
            cur = cur % K;
            if (cur == 0) return res;
            if (m[cur] == 1) return -1;
            m[cur] = 1;
            cur = cur * 10 + 1;
            res++;
        }
    }
}
