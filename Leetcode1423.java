package com.netease.music.leetcode.contest.no186;

/**
 * Created by dezhonger on 2020/04/27
 */
public class Leetcode1423 {
    public int maxScore(int[] cardPoints, int k) {
        int sum = 0;
        for (int x : cardPoints) sum += x;
        int t = 0;
        int remain = cardPoints.length - k;
        for (int i = 0; i < remain; i++) t += cardPoints[i];
        int minV = t;
        for (int i = remain; i < cardPoints.length; i++) {
            t += cardPoints[i];
            t -= cardPoints[i - remain];
            minV = Math.min(minV, t);
        }
        return sum - minV;
    }
}
