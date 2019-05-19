package com.netease.music.leetcode.contest.no137;

import java.util.Arrays;

/**
 * Created by dezhonger on 2019/5/19
 */
public class Leetcode1048 {
    public static void main(String[] args) {
        String[] s = new String[]{"wnyxmflkf", "xefx", "usqhb", "ttmdvv", "hagmmn", "tmvv", "pttmdvv", "nmzlhlpr", "ymfk", "uhpaglmmnn", "zckgh", "hgmmn", "isqxrk", "isqrk", "nmzlhpr", "uysyqhxb", "haglmmn", "xfx", "mm", "wymfkf", "tmdvv", "uhaglmmn", "mf", "uhaglmmnn", "mfk", "wnymfkf", "powttkmdvv", "kwnyxmflkf", "xx", "rnqbhxsj", "uysqhb", "pttkmdvv", "hmmn", "iq", "m", "ymfkf", "zckgdh", "zckh", "hmm", "xuefx", "mv", "iqrk", "tmv", "iqk", "wnyxmfkf", "uysyqhb", "v", "m", "pwttkmdvv", "rnqbhsj"};
//        System.out.println(new Leetcode1048().longestStrChain(s));
//        System.out.println(new Leetcode1048().longestStrChain(new String[]{"a", "b", "ba", "bca", "bda", "bdca"}));
        String[] s2 = new String[]{"bqtmbnugq","bjqtmbnuwsgq","m","btmnugq","czlhk","ihkgszexnh","wiszechhcxldcrow","kgszn","lhk","zlzfgmjurcntwvn","jjvodlrsmdmie","tm","ihqkgpszexnh","wnwpxg","zmun","hkgszenh","zmucnwn","kgzn","yjmk","wiszechcxldcrow","fnnh","yjm","jjvodlrmdmie","bqtmnugq","hkgszen","wehcxdrow","nhed","zmucn","wisehcxdrow","fnnlh","wehcxdro","zlzgmjurcntwvn","wnwg","jjvodlmde","wisechcxldcrow","wiehcxdrow","nhxyeedlcqxw","wehcxr","zzgmjurcnwvn","btmgq","nwdhslknbwpxg","ihqkgszexnh","jjvodlrsmdmhie","jjvodlmd","wdhslknbwpxg","nhedxw","wisehcxldcrow","btmugq","mfnnlfh","bqtmbnuwgq","nhedcxw","bqtmbnuwsgq","nhe","zzgmjurcntwvn","jjvodlrmdie","whslknwpxg","wdhslknwpxg","wsnwpxg","jjvodlm","hkgszexnh","zzgmjucnwvn","nhxyeedlcxw","nhxedcxw","zzmucnwn","hkgszn","zmucnw","whsnwpxg","czlmhk","whsknwpxg","wehcxro","wnwpg","nhxeedcxw","nwdhslknbjwpxg","nhedw","tmg","zlhk","zlzfgmjurcntwvnr","jjvodlmdie","zzmjucnwvn","mfnnlh","zzmjucnwn","wisehcxldrow","tmgq","nhxyeedcxw"};
        System.out.println(new Leetcode1048().longestStrChain(s2));
//        System.out.println(new Leetcode1048().longestStrChain(new String[]{"a", "a", "a"}));
//        System.out.println(new Leetcode1048().longestStrChain(new String[]{"a","b","ba","bca","bda","bdca"}));
    }

    int len;
    boolean[][] can;
    int[] dp;

    private boolean check(String s1, String s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 + 1 != len2) return false;
        //len1 + 1 <= len2 len1 < len2
        int i = 0;
        int j = 0;

        int c = 0;
        while (i < len1 && j < len2) {
            if (s1.charAt(i) == s2.charAt(j)) {
                i++;
                j++;
                c++;
            } else {
                j++;
            }
        }
        return c == len1;
    }

    private int dfs(int cur, String[] words) {
        if (dp[cur] != -1) {
            return dp[cur];
        }
        dp[cur] = 1;
        for (int i = 0; i < words.length; i++) {
            if (can[cur][i]) {
                dp[cur] = Math.max(dp[cur], dfs(i, words) + 1);
            }
        }
        return dp[cur];
    }

    public int longestStrChain(String[] words) {
        len = words.length;
        can = new boolean[len][len];
        dp = new int[len];
        Arrays.fill(dp, -1);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                can[i][j] = check(words[i], words[j]);

            }
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            dp[i] = dfs(i, words);
            res = Math.max(res, dp[i]);
        }
//        for (int i = 0; i < len; i++) {
//            System.out.println(i + " " + dp[i] + " " + words[i]);
//        }
        for (int i = 14; i >=1; i--) {
            for (int j = 0; j< len; j++) {
                if (dp[j] == i) {
                    System.out.println(i);
                    System.out.println(words[j]);
                }
            }
            System.out.println();
        }
        return res;

    }

}
