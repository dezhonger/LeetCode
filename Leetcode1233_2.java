package com.y2019.m12.d28;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by zhangweilong on 2019/12/28
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/28
 */
public class Leetcode1233_2 {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> res = new LinkedList<>();
        res.add(folder[0]);
        String last = folder[0];
        for (int i = 1; i < folder.length; i++) {
            if (!folder[i].startsWith(last + "/")) {
                res.add(folder[i]);
                last = folder[i];
            }
        }
        return res;
    }
}
