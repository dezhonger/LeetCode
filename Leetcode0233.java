package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dezhonger on 2020/04/26
 */
public class Leetcode0233 {

    public static void main(String[] args) {
//        System.out.println(new Leetcode0233().countDigitOne(13));
        System.out.println(new Leetcode0233().countDigitOne(20));
    }


    int[] a, dp, w;
    int n;

    int[] f(int n) {
        List<Integer> a = new ArrayList<>();
        while (n > 0) {
            a.add(n % 10);
            n /= 10;
        }
        int[] b = new int[a.size()];
        for (int i = 0; i < b.length; i++) b[i] = a.get(i);
        return b;
    }


    public int countDigitOne(int n) {
        if (n < 1) return 0;
        a = f(n);
        this.n = n;
        w = new int[a.length + 5];
        w[0] = 1;
        for (int i = 1; i < a.length; i++) w[i] = w[i - 1] * 10;
        dp = new int[a.length + 5];
        Arrays.fill(dp, -1);
        return dfs(a.length - 1, true);
    }

    private int dfs(int len, boolean limit) {
        if (!limit && dp[len] != -1) return dp[len];
        int r = limit ? a[len] : 9;
        int ans = 0;
        if (len == 0) {
            ans = r >= 1 ? 1 : 0;
        } else {
            for (int i = 0; i <= r; i++) {
                boolean nextLimit = limit && i == r;
                if (i == 1) {
                    if (nextLimit) {
                        if (len == 0) ans++;
                        else ans += Integer.valueOf((n + "").substring(a.length - len)) + 1;
                    } else ans += w[len];
                }
                ans += dfs(len - 1, nextLimit);
            }
        }
        dp[len] = ans;
        return ans;
    }

}
