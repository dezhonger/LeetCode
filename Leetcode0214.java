package com.y2019.m12.d08;

import java.util.Arrays;

/**
 * Created by zhangweilong on 2019/12/08
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/08
 *
 * kmp讲解: https://blog.csdn.net/f1033774377/article/details/82556438
 */
public class Leetcode0214 {

    public String shortestPalindrome(String s) {
        String str = s + "$" + new StringBuilder(s).reverse();
        int[] next = calNext(str);
        //根据下面next数组的意义， +1才是最长前缀后追的长度
        int maxLength = next[next.length - 1] + 1;
        return new StringBuilder(s.substring(maxLength)).reverse().append(s).toString();
    }


    //f数组表示前i个字符组成的字符串， 最长相同前缀后缀长度
    //为了实现方便，这里表示的是 最长相同前缀后缀长度-1
    int[] calNext(String str) {
        int[] f = new int[str.length()];
        //F[0]=-1 (虽说这里应该是０，但为了方便判越界，同时为了方便判断第0位与第i位，程序中这里置为-1)
        f[0] = -1;
        for (int i = 1; i < str.length(); i++) {
            int j = f[i - 1];
            while (str.charAt(j + 1) != str.charAt(i) && j >= 0) {
                j = f[j];
            }
            if (str.charAt(j + 1) == str.charAt(i)) f[i] = j + 1;
            else f[i] = -1;
        }
        return f;
    }
}
