package leetcode;

/**
 * Created by Dezhonger on 2017/2/12.
 */
public class Leetcode99 {
    public boolean isInterleave(String s1, String s2, String s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 + len2 != s3.length()) return false;
        boolean[][] dp = new boolean[len1 + 1][len2 + 1];
        dp[0][0] = true;
        for(int i = 0; i <= len1; i++) {
            for(int j = 0; j <= len2; j++) {
                if(i == 0 && j == 0) continue;
                char a, b, c;
                if(i == 0) {
                    b = s2.charAt(j - 1);
                    c = s3.charAt(j - 1);
                    dp[i][j] = dp[i][j-1] && (b == c);
                } else if(j == 0) {
                    a = s1.charAt(i - 1);
                    c = s3.charAt(i - 1);
                    dp[i][j] = dp[i - 1][j] && (a == c);
                } else {
                    a = s1.charAt(i - 1);
                    b = s2.charAt(j - 1);
                    c = s3.charAt(i + j - 1);
                    dp[i][j] |= dp[i][j-1] && (b == c);
                    dp[i][j] |= dp[i - 1][j] && (a == c);
                }
            }
        }
        return dp[len1][len2];
    }

    public static void main(String[] args) {
        System.out.println(new Leetcode99().isInterleave("aabcc", "dbbca", "aadbbcbcac"));
        System.out.println(new Leetcode99().isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    }
}
