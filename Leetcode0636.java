package com.dezhonger.y2019.m12.d24;

import java.util.List;
import java.util.Stack;

/**
 * Created by dezhonger on 2019/12/24
 *
 * @author dezhonger
 * @since 2019/12/24
 */
public class Leetcode0636 {

    //"0:start:0","1:start:2","1:end:5","0:end:6"
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] res = new int[n];
        Stack<Integer> stack = new Stack<>();
        int preTime = 0;
        for (int i = 0; i < logs.size();i ++) {
            String line = logs.get(i);
            String[] str = line.split(":", 3);
            int id = Integer.parseInt(str[0]);
            int time = Integer.parseInt(str[2]);
            if (!stack.empty()) {
                res[stack.peek()] += time - preTime;
            }
            preTime = time;
            if ("start".equals(str[1])) {
                stack.push(id);
            } else {
                res[stack.pop()]++;
                preTime++;
            }
        }
        return res;
    }

}
