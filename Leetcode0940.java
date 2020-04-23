package com.y2020.m04.d23;

/**
 * Created by zhangweilong on 2020/04/23
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/04/23
 */
public class Leetcode0940 {
    public int distinctSubseqII(String S) {
        long ans = 0;
        int[] cnt = new int[26];
        int mod = 10_0000_0007;
        for (char c : S.toCharArray()) {
            long tmp = 0 ;
            for (int x : cnt) tmp += x;
            cnt[c - 'a'] = (int) ((tmp + 1) % mod);
        }
        for (int x: cnt) ans += x;
        return (int) (ans % mod);
    }
}
