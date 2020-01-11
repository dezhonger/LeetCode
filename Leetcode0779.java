package com.y2020.m01.d11;

/**
 * Created by zhangweilong on 2020/01/11
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/11
 */
public class Leetcode0779 {
    //找规律，下一行的前半部分和上一行相同，接下来的一段是上一行的后半部分，再下一段是上一行的前半部分
    //n = 3, 0110
    //n = 4  0110 + 10(上一行后俩数) + 01(上一行前俩数)
    public int kthGrammar(int N, int K) {
        return find(N, K);
    }

    private int find(int n, int k) {
        if (n == 1) return 0;
        if (n == 2) return k - 1;
        int len = 1 << (n - 1);
        if (k <= len / 2) return find(n - 1, k);
        if (k <= len / 4 * 3) return find(n - 1, len / 4 + k - len / 2);
        if (k > len / 4 * 3) return find(n - 1, k - len / 4 * 3);
        //cannot reach here
        return -1;
    }

}
