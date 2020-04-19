package com.dezhonger.y2020.m04.d19;

/**
 * Created by dezhonger on 2020/04/19
 *
 * @author dezhonger
 * @since 2020/04/19
 */
public class Leetcode1419 {
    public int minNumberOfFrogs(String croakOfFrogs) {
        int ans = 0;
        int cur = 0;
        int[] cnt = new int[5];
        char[] ch = croakOfFrogs.toCharArray();
        for (int i = 0; i < ch.length; i++) {
            int index = "croak".indexOf(ch[i]);
            cnt[index]++;
            if (index == 0) {
                ans = Math.max(ans, ++cur);
            }
            if (index > 0 && cnt[index - 1] <= 0) return -1;
            if (index > 0) --cnt[index - 1];
            if (index == 4) cur--;
        }
        if (cur == 0) return ans;
        return -1;
    }
}
