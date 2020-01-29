package com.dezhonger.y2020.m01.d28;

/**
 * Created by dezhonger on 2020/01/29
 *
 * @author dezhonger
 * @since 2020/01/29
 */
public class Leetcode0777 {
    public static void main(String[] args) {
        System.out.println(new Leetcode0777().canTransform("RLRLRL", "LRLRLR"));
        System.out.println(new Leetcode0777().canTransform("RLRLX", "LRLRX"));
    }

    public boolean canTransform(String start, String end) {
        if (!start.replace("X", "").equals(end.replace("X", ""))) return false;
        int len = start.length();
        char[] c1 = start.toCharArray();
        char[] c2 = end.toCharArray();
        int i = 0, j = 0;
        while (i < len && j < len) {
            while (i < len && c1[i] == 'X') i++;
            while (j < len && c2[j] == 'X') j++;
            if (i == len && j == len) return true;
            if (i == len || j == len) return false;
            if (c1[i] != c2[j]) return false;
            if (c1[i] == 'L' && i < j) return false;
            if (c1[i] == 'R' && i > j) return false;
            i++;
            j++;
        }
        return true;
    }


}
