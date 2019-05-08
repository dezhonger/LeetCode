package com.dezhonger.y2019.m05;

import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/05/08
 *
 * @author dezhonger
 * @since 2019/05/08
 */
public class Leetcode0929 {
    public int numUniqueEmails(String[] emails) {
        Set<String> set = new HashSet<>();
        for (String s : emails) {
            int index = s.indexOf('@');
            String ed = s.substring(index + 1);
            s = s.substring(0, index);
            index = s.indexOf('+');
            if (index >= 0) s = s.substring(0, index);
            s = s.replace(".", "");
            set.add(s + "@" + ed);
        }
        return set.size();
    }
}
