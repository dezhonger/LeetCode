package com.netease.music.p20200214;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;

/**
 * Created by dezhonger on 2020/2/14
 */
public class Leetcode0388 {
    public static void main(String[] args) {
        String s = "dir\n    file.txt";
        System.out.println(new Leetcode0388().lengthLongestPath(s));
//        System.out.println(new Leetcode0388().lengthLongestPath2(s));
    }

    public int lengthLongestPath2(String input) {
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(0); // "dummy" length
        int maxLen = 0;
        for(String s:input.split("\n")){
            int lev = s.lastIndexOf("\t")+1; // number of "\t"
            while(lev+1<stack.size()) stack.pop(); // find parent
            int len = stack.peek()+s.length()-lev+1; // remove "/t", add"/"
            stack.push(len);
            // check if it is file
            if(s.contains(".")) maxLen = Math.max(maxLen, len-1);
        }
        return maxLen;
    }

    public int lengthLongestPath(String input) {
        if (input == null || input.length() == 0) return 0;
        int res = 1;

        Stack<Node> stack = new Stack<>();
        stack.push(new Node("", -1));

        String[] tokens = input.split("\n");
        int curValue = 0;
        for (String subToken : tokens) {
            int depth = findDepth(subToken);
            String token = subToken.substring(depth);
            boolean file = isFile(token);

            if (depth == stack.peek().depth + 1) {
                stack.push(new Node(token, depth));
                curValue += token.length();
                curValue++;
            } else {
                while (stack.peek().depth >= depth) {
                    Node pop = stack.pop();
                    curValue -= pop.s.length();
                    curValue--;
                }
                stack.push(new Node(token, depth));
                curValue += token.length();
                curValue++;
            }
            if (file) res = Math.max(res, curValue);
        }
        return res - 1;
    }

    private int findDepth(String s) {
        int i = 0;
        while (i < s.length() && s.charAt(i) == '\t') i++;
        return i;
    }

    private boolean isFile(String s) {
        return s.contains(".") && s.charAt(s.length() - 1) != '.';
    }


    class Node {
        String s;
        int depth;

        public Node(String s, int depth) {
            this.s = s;
            this.depth = depth;
        }
    }
}
