
/**
 * Created by Dezhonger on 2017/2/19.
 * 题目很简单，看到了一个更简单的写法。学习一下。
 */
public class Leetcode0482 {
    public String licenseKeyFormatting(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--)
            if (s.charAt(i) != '-')
                sb.append(sb.length() % (k + 1) == k ? '-' : "").append(s.charAt(i));
        return sb.reverse().toString().toUpperCase();
    }
}
