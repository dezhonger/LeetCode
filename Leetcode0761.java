package com.netease.music.leetcode;

import com.google.common.collect.Lists;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2020/4/10
 */
public class Leetcode0761 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0761().makeLargestSpecial("11011000"));
    }
    //把1视为左括号,0视为右括号
    public String makeLargestSpecial(String S) {
        int len = S.length();
        int cnt = 0;
        int left = 0;
        List<String> sortList = new ArrayList<>();
        for (int i = 0; i < len; i++) {
            char c = S.charAt(i);
            if (c == '1') cnt++;
            else cnt--;
            if (cnt == 0) {
                //递归处理子问题
                sortList.add("1" + makeLargestSpecial(S.substring(left + 1, i)) + "0");
                left = i + 1;
            }
        }
        Collections.sort(sortList, Collections.reverseOrder());
        return String.join("", sortList);
    }
}
