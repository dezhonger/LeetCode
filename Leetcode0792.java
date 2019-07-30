//package com.y2019.m07.d30;
//
///**
// * Created by zhangweilong on 2019/07/30
// *
// * @author zhangweilong@corp.netease.com
// * @since 2019/07/30
// */
//
//
//
//public class Leetcode0792 {
//
//    int[] f = new int[5050];
//
//    void getfail(String p, int[] f) {
//        f[0] = 0;
//        f[1] = 0;
//        int m = p.length();
//        for (int i = 1; i < m; i++) {
//            int j = f[i];
//            while (j > 0 && p.charAt(i + 1) != p.charAt(j + 1)) j = f[j];
//            f[i + 1] = p.charAt(i + 1) == p.charAt(j + 1) ? j + 1 : 0;
//        }
//    }
//
//
//    void find(String t, String p, int[] f) {
//        int i;
//        getfail(p, f);
//        int j = 0;
//        for (int i = 0; i < n; i++)
//        rep(i, n)
//        {
//            while (j && p[j] != t[i]) j = f[j];
//            if (p[j] == t[i]) j++;
//            if (j == m) {
//
//                printf("%d\n", i - m + 1 + 1);
//                flag = 1;
//                return;
//            }
//        }
//    }
//
//    public int numMatchingSubseq(String S, String[] words) {
//
//    }
//}
