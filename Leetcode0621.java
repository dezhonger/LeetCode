package com.dezhonger.y2019.m11.d27;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/11/29
 *
 * @author dezhonger
 * @since 2019/11/29
 */
public class Leetcode0621 {
    int[] cnt = new int[26];
    int[] last = new int[26];

    public int leastInterval(char[] tasks, int n) {
        if (tasks == null || tasks.length == 0) return 0;
        int length = tasks.length;
        Arrays.fill(last, -1000);
        for (char ch : tasks) {
            cnt[ch - 'a']++;
        }
        int pos = 0;
        while (true) {
            int letter = getMaxLetterCanUse(pos, n);
            if (letter == -1) pos++;
            else {
                cnt[letter]--;
                last[letter] = pos;
                length--;
                pos++;
                if (length == 0) break;
            }

        }
        return pos;
    }

    private int getMaxLetterCanUse(int pos, int n) {
        int res = -1;
        int ct = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0 || pos - last[i] <= n) {
                continue;
            }
            if (res == -1) {
                res = i;
                ct = Math.max(ct, cnt[i]);
            } else {
                if (cnt[i] > ct) {
                    ct = cnt[i];
                    res = i;
                }
            }
        }
        return res;
    }
}
