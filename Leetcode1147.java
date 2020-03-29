package com.y2020.m03.d29;

/**
 * Created by zhangweilong on 2020/03/29
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/03/29
 */
public class Leetcode1147 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1147().longestDecomposition("ghiabcdefhelloadamhelloabcdefghi"));
        System.out.println(new Leetcode1147().longestDecomposition("merchant"));
        System.out.println(new Leetcode1147().longestDecomposition("antaprezatepzapreanta"));
        System.out.println(new Leetcode1147().longestDecomposition("aaa"));
    }
    public int longestDecomposition(String text) {
        int ans = 0;
        int len = text.length();
        int left = 0, right = len;
        while (true) {
            boolean f = false;
            for (int k = 1; k <= (right - left) / 2; k++) {
                String s1 = text.substring(left, left + k);
                String s2 = text.substring(right - k, right);
                if (s1.equals(s2)) {
                    ans += 2;
                    left += k;
                    right -= k;
                    f = true;
                    break;
                }
            }
            if (!f) {
                if (left < right) ans++;
                break;
            }
        }
        return ans;
    }
}
