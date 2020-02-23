package com.netease.music.p20200223;

import com.netease.music.p20190526.jdk8.In;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

/**
 * Created by dezhonger on 2020/2/23
 */
public class Leetcode0828 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0828().uniqueLetterString("ABC"));
        System.out.println(new Leetcode0828().uniqueLetterString("ABA"));
        System.out.println(new Leetcode0828().uniqueLetterString("LEETCODE"));
    }

    public int uniqueLetterString(String s) {
        char[] ch = s.toCharArray();
        int len = s.length();
        long res = 0;
        int mod = 10_0000_0007;

        int[] left = new int[len];
        int[] right = new int[len];
        int[] letter = new int[26];
        Arrays.fill(letter, -1);
        for (int i = 0; i < len; i++) {
            //在它左边和他字母相同最近的位置
            left[i] = letter[ch[i] - 'A'];
            letter[ch[i] - 'A'] = i;
        }

        Arrays.fill(letter, len);
        for (int i = len - 1; i >= 0; i--) {
            //在它右边和他字母相同最近的位置
            right[i] = letter[ch[i] - 'A'];
            letter[ch[i] - 'A'] = i;
        }

        //计算每个字母对结果的贡献，也就是计算这个字母什么时候可以成为一个uniqueLetter
        for (int i = 0; i < len; i++) {
            int l = i - left[i];
            int r = right[i] - i;
            res += l * r;
            res %= mod;
        }
        return (int) res;

    }
}
