package leetcode;

import java.util.Stack;

/**
 * Created by zwl on 2016/10/20.
 */

/**
 * 维护一个单调栈
 */
public class Leetcode402 {
    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>();
        int len = num.length();
        if(k >+ len) return "0";
        String str = "";
        for(int i = 0; i < len; i++) {
            char cur = num.charAt(i);
            //当前元素比栈顶元素小 且 剩下的元素个数不能比需要的元素的个数小
            while(!stack.isEmpty() && cur < stack.peek() && len - i - 1 >= (len - k - stack.size())) {
                stack.pop();
            }
            if(stack.size() < len - k) {
                stack.push(cur);
            }
        }
        while(!stack.isEmpty()) {
            str = stack.pop() + str;
        }

        int h = 0;
        while(h < str.length() && str.charAt(h) == '0') h++;
        str = str.substring(h);
        if(str.length() == 0) str = "0";
//        System.out.println(str);
        return str;
    }

    public static void main(String[] args) {
        new Leetcode402().removeKdigits("1432219", 3);
        new Leetcode402().removeKdigits("10200", 1);
        new Leetcode402().removeKdigits("10", 2);
    }
}
