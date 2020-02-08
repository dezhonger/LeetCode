package com.netease.music.p20200208;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2020/2/8
 */
public class Leetcode0659 {
    public boolean isPossible(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        Map<Integer, Integer> append = new HashMap<>();
        for (int x : nums) cnt.put(x, cnt.getOrDefault(x, 0) + 1);

        for (int x : nums) {
            if (cnt.getOrDefault(x, 0) == 0) continue;

            if (append.getOrDefault(x, 0) > 0) {
                append.put(x, append.get(x) - 1);
                append.put(x + 1, append.getOrDefault(x + 1, 0) + 1);

                cnt.put(x, cnt.get(x) - 1);
            } else if (cnt.getOrDefault(x, 0) > 0 && cnt.getOrDefault(x + 1, 0) > 0 && cnt.getOrDefault(x + 2, 0) > 0) {
                cnt.put(x, cnt.get(x) - 1);
                cnt.put(x + 1, cnt.get(x + 1) - 1);
                cnt.put(x + 2, cnt.get(x + 2) - 1);
                append.put(x + 3, append.getOrDefault(x + 3, 0) + 1);
            } else {
                return false;
            }
        }
        return true;
    }
}
