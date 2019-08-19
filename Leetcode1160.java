
/**
 * Created by dezhonger on 2019/8/19
 */
public class Leetcode1160 {
    public int countCharacters(String[] words, String chars) {
        int[] c = new int[26];
        for (char ch : chars.toCharArray()) c[ch - 'a']++;
        int res = 0;
        for (String s : words) res += check(c, s);
        return res;
    }

    private int check(int[] c, String s) {
        int[] d = new int[26];
        for (char ch : s.toCharArray()) d[ch - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (d[i] > c[i]) return 0;
        }
        return s.length();
    }
}
