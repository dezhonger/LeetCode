package com.dezhonger.y2020.m04.d01;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.NavigableSet;
import java.util.PriorityQueue;
import java.util.TreeMap;

/**
 * Created by dezhonger on 2020/04/03
 *
 * @author dezhonger
 * @since 2020/04/03
 */
public class Leetcode0895 {


}
class FreqStack {
    Map<Integer, List<Integer>> mp;
    Map<Integer, Integer> mc;
    int maxFrequency;
    public FreqStack() {
        mc = new HashMap<>();
        mp = new HashMap<>();
        maxFrequency = 0;
    }

    public void push(int x) {
        int c = mc.getOrDefault(x, 0) + 1;
        maxFrequency = Math.max(c, maxFrequency);
        mc.put(x, c);
        List<Integer> list = mp.getOrDefault(c, new ArrayList<>());
        list.add(x);
        mp.put(c, list);
    }

    public int pop() {
        List<Integer> list = mp.get(maxFrequency);
        int size = list.size();
        int v = list.get(size - 1);
        list.remove(size - 1);
        mp.put(maxFrequency, list);
        if (size == 1) maxFrequency--;
        mc.put(v, mc.get(v) - 1);
        return v;
    }

}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */