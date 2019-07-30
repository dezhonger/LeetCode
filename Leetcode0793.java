package com.netease.music.p20190730;

/**
 * Created by dezhonger on 2019/7/30
 */
public class Leetcode0793 {
    public static void main(String[] args) {
        new Leetcode0793().preimageSizeFZF(79);
    }
    //cal zeros of 5*x
    int f(int x) {
        int res = x;
        while (x > 0) {
            res += x / 5;
            x /= 5;
        }
        return res;
    }

    public int preimageSizeFZF(int K) {
        int r = K;
        int l = 0;
        while (l < r) {
            int mid = (l + r) / 2;
            int cnt = f(mid);
            if (cnt == K) return 5;
            if (cnt < K) l = mid + 1;
            else r = mid - 1;
        }
        return f(l) == K ? 5 : 0;
    }
}
