package com.netease.music.rep2.elephant.consumer.handler;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangweilong on 2019/06/09
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/06/09
 */
public class Leetcode5083 {
    public static void main(String[] args) {
        new Leetcode5083().findOcurrences("alice is a good girl she is a good student", "a", "good");
    }
    public String[] findOcurrences(String text, String first, String second) {
        String[] s = text.split(" ");
        List<String> l = new ArrayList<>();
        for (int i = 2; i < s.length; i++) {
            if (s[i - 2].equals(first) && s[i - 1].equals(second)) l.add(s[i]);
        }
        return l.toArray(new String[0]);
    }
}
