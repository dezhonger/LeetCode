
/**
 * Created by dezhonger on 2019/9/15
 */
public class Leetcode1190 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1190().reverseParentheses("kkqlqdjsynxizwmmiw()nbw(((ce)))"));
    }

    public String reverseParentheses(String s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                start = i;
            } else if (s.charAt(i) == ')') {
                end = i;
                String sb = s.substring(start + 1, end);
                return reverseParentheses(s.substring(0, start) + new StringBuilder(sb).reverse().toString() + s.substring(end + 1));
            }
        }
        return s;
    }

}
