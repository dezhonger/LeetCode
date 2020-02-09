package com.dezhonger.y2020.m02.d10;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2020/02/10
 *
 * @author dezhonger
 * @since 2020/02/10
 */
public class Leetcode0722 {
    public static void main(String[] args) {
        Leetcode0722 sol = new Leetcode0722();
        String[] source = new String[]{
                "/*Test program */",
                "int main()",
                "{ ",
                "  // variable declaration ",
                "int a, b, c;", "/* This is a test",
                "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"
        };

        String[] s = new String[]{
                "a/*comment", "line", "more_comment*/b"
        };

        String[] s2 = new String[]{
                "main() {", "/* here is commments", "  // still comments */", "   double s = 33;", "   cout << s;", "}"
        };


        String[] s3 = new String[]{
                "main() {", "   int x = 1; // Its comments here", "   x++;", "   cout << x;", "   //return x;", "   x--;", "}"
        };
        List<String> strings = sol.removeComments(s3);
        for (String string : strings) {
            System.out.println(string);

        }
    }


    String join(String[] s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length; i++) {
            sb.append(s[i]).append("\n");
        }
        return sb.toString();
    }


    public List<String> removeComments(String[] source) {
        List<String> res = new ArrayList<>();
        StringBuilder r = new StringBuilder();

        String str = join(source);

        int pre = 0;
        while (true) {
            int s0 = str.indexOf("//", pre);
            int s = str.indexOf("/*", pre);

            if ((s != -1 && s < s0) || s0 == -1) {
                int e = str.indexOf("*/", s + 2);
                if (s == -1) {
                    r.append(str.substring(pre));
                    break;
                }
                r.append(str.substring(pre, s));
                pre = e + 2;
            } else {
                int e0 = str.indexOf("\n", s0 + 2);
                r.append(str.substring(pre, s0)).append("\n");
                pre = e0 + 1;
            }

        }

        String[] split = r.toString().split("\n");
        for (String s : split) {
            if (s.length() == 0) continue;
            if (s.length() == 1 && s.charAt(0) == '\n') continue;
            res.add(s);
        }
        return res;
    }
}
