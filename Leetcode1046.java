package com.netease.music.leetcode.contest.no137;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/5/19
 */
public class Leetcode1046 {
    public static void main(String[] args) {
        new Leetcode1046().lastStoneWeight(new int[]{2,7,4,1,8,1});
    }
    public int lastStoneWeight(int[] stones) {
        if (stones.length == 1) return stones[0];
        int len = stones.length;
        Arrays.sort(stones);
        while(true) {
            int x1 = stones[stones.length - 1];
            int x2 = stones[stones.length - 2];
            if (x1 == x2) {
                int[] b = new int[stones.length - 2];
                for (int j = 0; j < b.length; j++) b[j] = stones[j];
                stones = new int[b.length];
                for (int j = 0; j < b.length; j++) stones[j] = b[j];

            } else {
                int[] b = new int[stones.length - 1];
                for (int j = 0; j < b.length - 1; j++) b[j] = stones[j];
                b[b.length - 1] = Math.abs(x1 - x2);
                stones = new int[b.length];
                for (int j = 0; j < b.length; j++) stones[j] = b[j];
            }
            if (stones.length == 1) return stones[0];
            else if(stones.length == 0) return 0;
            Arrays.sort(stones);
        }
    }
}
