package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/5/21
 */
public class Leetcode0868 {
    public int binaryGap(int N) {
        String s = Integer.toBinaryString(N);
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') list.add(i);
        }
        if (list.size() == 1) return 0;
        else {
            int ma = Integer.MIN_VALUE;
            for (int i = 1; i < list.size(); i++) {
                ma = Math.max(ma, list.get(i) - list.get(i - 1));
            }
            return ma;
        }
    }
}
