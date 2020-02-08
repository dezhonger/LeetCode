package com.netease.music.p20200208;


/**
 * Created by dezhonger on 2020/2/8
 */
public class Leetcode0395 {

    public static void main(String[] args) {
        System.out.println(new Leetcode0395().longestSubstring("aaa", 3));
        System.out.println(new Leetcode0395().longestSubstring("aaabb", 3));
        System.out.println(new Leetcode0395().longestSubstring("ababbc", 2));
        System.out.println(new Leetcode0395().longestSubstring("ababacb", 3));
        System.out.println(new Leetcode0395().longestSubstring("bbaaacbd", 3));
    }

    public int longestSubstring(String s, int k) {
        int res = 0;
        int len = s.length();
        char[] ch = s.toCharArray();
        for (int unique = 0; unique < 26; unique++) {

            int left = 0;
            //当前窗口有多少个不同的字母
            int a = 0;
            //当前窗口有多少 字母的次数是 <= k 的
            int b = 0;
            int[] cnt = new int[26];

            for (int right = 0; right < len; right++) {
                int letter = ch[right] - 'a';
                if (cnt[letter] == 0) {
                    //新的字母
                    a++;
                }
                cnt[letter]++;
                if (cnt[letter] == k) b++;

                if (a > unique) {
                    while (left < right) {
                        cnt[ch[left] - 'a']--;
                        if (cnt[ch[left] - 'a'] == 0) a--;
                        if (cnt[ch[left] - 'a'] == k - 1) b--;
                        left++;
                        if (a == unique) break;
                    }
                }
                if (a == unique && b == unique) res = Math.max(res, right - left + 1);
            }
        }
        return res;
    }
}
