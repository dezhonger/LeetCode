package com.y2019.m08.d24;


/**
 * Created by zhangweilong on 2019/08/24
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/08/24
 */
public class Leetcode0115 {

    public String reverseWords(String s) {
        s = s.trim();
        String[] s1 = s.split(" +");
        StringBuilder sb = new StringBuilder();
        for (int i = s1.length - 1; i > 0; i--) sb.append(s1[i]).append(" ");
        sb.append(s1[0]);
        return sb.toString();
    }
}
