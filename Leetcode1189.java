
/**
 * Created by dezhonger on 2019/9/15
 */
public class Leetcode1189 {
    public int maxNumberOfBalloons(String text) {
        int[] c = new int[26];
        for (char d : text.toCharArray()) {
            c[d - 'a']++;
        }
        int res = Integer.MAX_VALUE;
        res = Math.min(res, c['a' - 'a']);
        res = Math.min(res, c['b' - 'a']);
        res = Math.min(res, c['n' - 'a']);
        res = Math.min(res, c['l' - 'a'] / 2);
        res = Math.min(res, c['o' - 'a'] / 2);
        return res;
    }
}
