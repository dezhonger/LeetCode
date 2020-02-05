package com.netease.music.p20200205;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/2/6
 */
public class Leetcode0833 {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        int len = S.length();
        int[] c = new int[len];
        Arrays.fill(c, -1);
        for (int i = 0; i < indexes.length; i++) {
            int l = sources[i].length();
            //肯定不相等
            if (indexes[i] + l > len) continue;
            String sub = S.substring(indexes[i], indexes[i] + sources[i].length());
            if (sub.equals(sources[i])) c[indexes[i]] = i;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len;) {
            if (c[i] < 0) {
                sb.append(S.charAt(i++));
            } else {
                int ind = c[i];
                int l = sources[ind].length();
                sb.append(targets[ind]);
                i += l;
            }
        }
        return sb.toString();
    }
}
