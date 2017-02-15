/**
 * Created by dezhonger on 2016/8/3.
 */
public class Solution {
    public int numDistinct(String s, String t) {
        if(s == null || t == null) return 0;
        int x = s.length(), y = t.length();
        if(x < y || x == 0) return 0;
        int[][] dp = new int[x+1][y+1];
        dp[0][0] = 1;
        for(int i = 1; i <= x; i++) {
            for(int j = 0; j <= y && j <= i; j++) {
                if(j == 0) dp[i][j] = 1;
                else {
                    if(s.charAt(i-1) == t.charAt(j-1)) {
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[s.length()][t.length()];
    }

    public static void main(String[] args) {
        System.out.println(new Solution().numDistinct(new String("rabbbit"), new String("rabbit")));
        System.out.println(new Solution().numDistinct(new String("b"), new String("a")));
    }
}
