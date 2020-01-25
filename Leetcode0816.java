package com.dezhonger.y2020.m01.d25;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by dezhonger on 2020/01/26
 *
 * @author dezhonger
 * @since 2020/01/26
 */
public class Leetcode0816 {
    List<String> res = new LinkedList<>();
    public List<String> ambiguousCoordinates(String S) {
        int len = S.length();
        String sub = S.substring(1, len - 1);
        for (int i = 1; i < sub.length(); i++) {
            String s1 = sub.substring(0, i);
            String s2 = sub.substring(i);

            List<String> f1 = f(s1);
            List<String> f2 = f(s2);
            for (String x : f1) for (String y : f2) {
                String t = "(" + x + ", " + y + ")";
                res.add(t);
            }
        }
        return res;
    }


    private List<String> f(String s) {
        List<String> r = new LinkedList<>();
        if (s.length() == 1 || s.length() > 1 && s.charAt(0) != '0') r.add(s);

        //小数最后一位是0
        if (s.charAt(s.length() - 1) == '0') return r;
        for (int i = 1; i < s.length(); i++) {
            String zhengshu = s.substring(0, i);
            //0:true 01:false
            if (zhengshu.length() >= 2 && zhengshu.charAt(0) == '0') break;
            String xiaoshu = s.substring(i);
            String tmp = zhengshu + "." + xiaoshu;
            r.add(tmp);
        }
        return r;
    }
}
