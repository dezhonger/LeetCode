package com.netease.music.p20190717;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/7/17
 */
public class Leetcode0869 {

    public boolean reorderedPowerOf2(int N) {
        Set<String> set = new HashSet<>();
        for (int i = 0; i < 30; i++) {
            int t = 1 << i;
            char[] chars = (t + "").toCharArray();
            Arrays.sort(chars);
            set.add(new String(chars));
        }
        char[] n = (N + "").toCharArray();
        Arrays.sort(n);
        return set.contains(new String(n));
    }
}
