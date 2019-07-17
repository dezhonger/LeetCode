package com.netease.music.rep2.taskman.service.config;

/**
 * Created by zhangweilong on 2019/07/17
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/07/17
 */
public class Leetcode0904 {
    public int totalFruit(int[] tree) {
        int[] cnt = new int[40010];
        int l = 0;
        int types = 0;
        int result = -1;
        for (int r = 0; r < tree.length; r++) {
            if (++cnt[tree[r]] == 1) {
                types++;
            }
            while (types > 2) {
                if (--cnt[tree[l]] == 0) {
                    types--;
                }
                l++;
            }
            result = Math.max(result, r - l + 1);
        }
        return result;
    }
}
