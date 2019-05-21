package com.netease.music.leetcode;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

/**
 * Created by dezhonger on 2019/5/21
 */
public class Leetcode0950 {
    public static void main(String[] args) {
        new Leetcode0950().deckRevealedIncreasing(new int[]{17, 13, 11, 2, 3, 5, 7});
    }
    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck);
        int[] r = new int[deck.length];
        int t = 0;
        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < deck.length; i++) queue.add(i);
        while (!queue.isEmpty()) {
            int x = queue.poll();
            r[t++] = x;
            if (!queue.isEmpty()) {
                x = queue.poll();
                queue.add(x);
            }
        }
        int[] res = new int[r.length];
        for (int i = 0; i < r.length; i++) {
            res[r[i]] = deck[i];
        }
        return res;
    }
}
