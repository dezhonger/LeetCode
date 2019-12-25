package com.y2019.m12.d26;

/**
 * Created by zhangweilong on 2019/12/25
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/25
 */
public class Leetcode0825 {
    public int numFriendRequests(int[] ages) {
        int[] cnt = new int[130];
        for (int x : ages) cnt[x]++;
        int res = 0;
        for (int i = 15; i <= 120; i++) {
            int number = cnt[i];
            //多少人可以与年龄为i的人发送请求
            cnt[i] += cnt[i - 1];
            res = res + number * (cnt[i] - cnt[i / 2 + 7] - 1);
        }
        return res;
    }
}
