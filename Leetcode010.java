/**
 * Created by dezhonger on 2016/8/3.
 */
//Some examples:
//        isMatch("aa","a") ¡ú false
//        isMatch("aa","aa") ¡ú true
//        isMatch("aaa","aa") ¡ú false
//        isMatch("aa","a*") ¡ú true
//        isMatch("aa",".*") ¡ú true
//        isMatch("ab",".*") ¡ú true
//        isMatch("aab","c*a*b") ¡ú true

public class Solution {

    public boolean f(String s, String p, int k1, int k2, int l1, int l2) {
        if(k1 == l1 && k2 == l2) return true;
        if(k2 == l2 && k1 < l1) return false;
        if(l1 == k1 && k2 < l2) {
            if(k2 + 1 < l2 && p.charAt(k2 + 1) == '*') {
                return f(s, p, k1, k2 + 2, l1, l2);
            }
            return false;
        }
        while(k1 < l1 && k2 < l2) {
            if((k2 + 1 < l2 && p.charAt(k2 + 1) != '*') || k2 + 1 == l2) {
                if(p.charAt(k2) == '.' || p.charAt(k2) == s.charAt(k1)) {
                    return f(s, p, k1 + 1, k2 + 1, l1, l2);
                }
                return false;
            }
            else {
                if(p.charAt(k2) == '.') {
                    boolean ans = f(s, p, k1, k2 + 2, l1, l2);
                    for(int i = 1; k1 + i <= l1; i++) {
                        ans |= f(s, p, k1 + i, k2 + 2, l1, l2);
                    }
                    return ans;

                }
                else {
                    boolean ans = f(s, p, k1, k2 + 2, l1, l2);
                    for(int i = 1; k1 + i <= l1 && s.charAt(k1 + i - 1) == p.charAt(k2); i++) {
                        ans |= f(s, p, k1 + i, k2 + 2, l1, l2);
                    }
                    return ans;
                }
            }
        }
        return false;
    }
    public boolean isMatch(String s, String p) {
        int k1 = 0, k2 = 0;
        int l1 = s.length(), l2 = p.length();
        return f(s, p, 0, 0, l1, l2);


    }

    public static void main(String[] args) {
        String s = "a";
        String p = "a1*b*";
        System.out.println(new Solution().isMatch(s, p));
    }
}
