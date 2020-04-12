package com.netease.music.leetcode;

import java.util.Arrays;

/**
 * Created by dezhonger on 2020/4/13
 */
public class Leetcode1235 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1235().jobScheduling(
                new int[]{1, 2, 3, 3},
                new int[]{3, 4, 5, 6},
                new int[]{50, 10, 40, 70}
        ));

        System.out.println(new Leetcode1235().jobScheduling(
                new int[]{1, 2, 3, 4, 6},
                new int[]{3, 5, 10, 6, 9},
                new int[]{20, 20, 100, 70, 60}
        ));

        System.out.println(new Leetcode1235().jobScheduling(
                new int[]{1, 1, 1},
                new int[]{2, 3, 4},
                new int[]{5, 6, 4}
        ));
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int len = startTime.length;
        Work[] works = new Work[len + 1];
        works[0] = new Work(-1, -1, 0);
        for (int i = 0; i < len; i++) works[i + 1] = new Work(startTime[i], endTime[i], profit[i]);
        Arrays.sort(works);
        int[] prefixMax = new int[len + 1];
        int[] dp = new int[len + 1];
        dp[0] = prefixMax[0] = 0;
        for (int i = 1; i <= len; i++) {
            dp[i] = dp[0] + works[i].p;
            int j = binaryIndex(works, 0, i - 1, works[i].s);
            dp[i] = Math.max(dp[i], prefixMax[j] + works[i].p);
            prefixMax[i] = Math.max(prefixMax[i - 1], dp[i]);
        }
        return prefixMax[len];
    }

    //找到 <=s 的最大值
    private int binaryIndex(Work[] works, int l, int r, int s) {
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (works[mid].e > s) r = mid - 1;
            else l = mid;
        }
        return l;
    }


    class Work implements Comparable<Work> {
        int s, e, p;

        public Work(int s, int e, int p) {
            this.s = s;
            this.e = e;
            this.p = p;
        }

        @Override
        public int compareTo(Work o) {
            return Integer.compare(e, o.e);
        }
    }
}
