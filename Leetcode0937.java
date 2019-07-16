package com.netease.music.p20190716;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2019/7/16
 */
public class Leetcode0937 {


    private boolean isLetter(String log) {
        int index = log.indexOf(" ");
        return log.charAt(index + 1) >= 'a' && log.charAt(index + 1) <= 'z';
    }

    public String[] reorderLogFiles(String[] logs) {
        List<String> letters = new ArrayList<>();
        List<String> digits = new ArrayList<>();
        for (String log : logs) {
            if (isLetter(log)) {
                letters.add(log);
            } else {
                digits.add(log);
            }

        }
        Collections.sort(letters, (o1, o2) -> {
            int index1 = o1.indexOf(" ");
            int index2 = o2.indexOf(" ");
            String s1 = o1.substring(0, index1);
            String t1 = o1.substring(index1 + 1);
            String s2 = o2.substring(0, index2);
            String t2 = o2.substring(index2 + 1);
            if (t1.equals(t2)) {
                return s1.compareTo(s2);
            } else {

            }return t1.compareTo(t2);
        });
        String[] res = new String[logs.length];
        int c = 0;
        for (String letter : letters) {
            res[c++] = letter;
        }
        for (String digit : digits) {
            res[c++] = digit;
        }
        return res;
    }
}
