package com.netease.music.p20200208;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * Created by dezhonger on 2020/2/8
 */
public class Leetcode0649 {
    public String predictPartyVictory(String senate) {
        Queue<Integer> d = new ArrayDeque<>();
        Queue<Integer> r = new ArrayDeque<>();
        int n = senate.length();
        for (int i = 0; i < n; i++) {
            if (senate.charAt(i) == 'D') d.add(i);
            else r.add(i);
        }

        while (!d.isEmpty() && !r.isEmpty()) {
            while (!d.isEmpty() && !r.isEmpty()) {
                int dpoll = d.poll();
                int rpoll = r.poll();
                if (dpoll < rpoll) d.add(dpoll + n);
                else r.add(rpoll + n);
            }
        }
        return d.isEmpty() ? "Radiant" : "Dire";
    }
}
