
import java.util.Stack;

/**
 * Created by zhangweilong on 2019/08/01
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/08/01
 */
public class Leetcode0921 {

    public int minAddToMakeValid(String S) {
        Stack<Character> stack = new Stack<>();
        int res = 0;
        for (char c : S.toCharArray()) {
            if (c == '(') stack.push(c);
            else {
                if (stack.isEmpty()) res++;
                else stack.pop();
            }
        }
        return res + stack.size();
    }
}
