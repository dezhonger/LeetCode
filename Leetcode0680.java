
/**
 * Created by zhangweilong on 2019/07/30
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/07/30
 */
public class Leetcode0680 {
    public static void main(String[] args) {
        boolean ebcbbececabbacecbbcbe = new Leetcode0680().validPalindrome("ebcbbececabbacecbbcbe");
        System.out.println(ebcbbececabbacecbbcbe);
    }

    boolean c1(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }

    boolean c2(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l) == s.charAt(r)) {
                l++;
                r--;
            } else {
                if (l + 1 == r) return true;
                else {
                    boolean ans1 = false;
                    boolean ans2 = false;
                    if (s.charAt(l) == s.charAt(r - 1)) {
                        ans1 = c1(s, l + 1, r - 2);
                    }
                    if (s.charAt(l + 1) == s.charAt(r)) {
                        ans2 = c1(s, l + 2, r - 1);
                    }
                    return ans1 || ans2;
                }
            }
        }
        return true;
    }

    public boolean validPalindrome(String s) {
        int len = s.length();
        int i = 0, j = len - 1;
        if (c1(s, i, j)) return true;
        return c2(s, i, j);
    }
}
