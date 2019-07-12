package com.dezhonger.y2019.m07.d12;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

/**
 * Created by dezhonger on 2019/07/12
 *
 * @author dezhonger
 * @since 2019/07/12
 */
public class Leetcode0884 {
    public String[] uncommonFromSentences(String A, String B) {
        List<String> r = new ArrayList<>();
        Map<String, Long> a = Arrays.stream(A.split(" ")).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        Map<String, Long> b = Arrays.stream(B.split(" ")).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        for (Map.Entry<String, Long> entry: a.entrySet()) {
            if (entry.getValue() == 1 && !b.containsKey(entry.getKey())) {
                r.add(entry.getKey());
            }
        }
        for (Map.Entry<String, Long> entry: b.entrySet()) {
            if (entry.getValue() == 1 && !a.containsKey(entry.getKey())) {
                r.add(entry.getKey());
            }
        }
        return r.toArray(new String[0]);
    }
}
