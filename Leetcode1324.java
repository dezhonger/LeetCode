package com.dezhonger.y2020.m01.d19;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by dezhonger on 2020/01/20
 *
 * @author dezhonger
 * @since 2020/01/20
 */
public class Leetcode1324 {
    public List<String> printVertically(String s) {
        String[] str = s.split(" ");
        int ma = 0;
        for (String fs : str) {
            ma = Math.max(ma, fs.length());
        }
        StringBuilder[] sb = new StringBuilder[ma];
        for (int i = 0; i < sb.length; i++) sb[i] = new StringBuilder();
        for (int i = 0; i < str.length; i++) {
            String fs = str[i];
            int j = 0;
            for (j = 0; j < fs.length(); j++) {
                sb[j].append(fs.charAt(j));
            }
            while (j < ma) {
                sb[j++].append(" ");
            }
        }
        List<String> res = new LinkedList<>();
        for (int i = 0; i < sb.length; i++) {
            StringBuilder tmp = new StringBuilder();
            int j = sb[i].length() - 1;
            while (sb[i].charAt(j) == ' ') j--;

            res.add(sb[i].substring(0, j + 1));
        }
        return res;
    }
}
