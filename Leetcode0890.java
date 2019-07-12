
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dezhonger on 2019/07/12
 *
 * @author dezhonger
 * @since 2019/07/12
 */
public class Leetcode0890 {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> r = new ArrayList<>();
        for (String s : words) {
            if (check(s, pattern)) r.add(s);
        }
        return r;
    }

    private boolean check(String s, String pattern) {
        if (s.length() !=pattern.length()) return false;
        int[] map = new int[26];
        int[] map2 = new int[26];
        Arrays.fill(map, -1);
        Arrays.fill(map2, -1);
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'a';
            if (map[c] == -1) {
                int d = pattern.charAt(i) - 'a';
                if (map2[d] == -1) {
                    map[c] = d;
                    map2[d] = c;
                } else {
                    return false;
                }
            } else {
                if (map[c] != pattern.charAt(i) - 'a') return false;
            }
        }
        return true;
    }
}
