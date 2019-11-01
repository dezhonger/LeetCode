
import java.util.List;

/**
 * Created by dezhonger on 2019/11/01
 *
 * @author dezhonger
 * @since 2019/11/01
 */
public class Leetcode1239 {
    public int maxLength(List<String> arr) {
        int len = arr.size();
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < (1 << len); i++) {
            int[] c = new int[26];
            boolean f = true;
            int t = 0;
            for (int j = 0; j < len; j++) {
                if ((1 & (i >> j)) == 1) {
                    t += arr.get(j).length();
                    for (char ch : arr.get(j).toCharArray()) {
                        c[ch - 'a']++;
                        if (c[ch - 'a'] > 1) {
                            f = false;
                        }
                    }
                }
            }
            if (f) res = Math.max(res, t);
        }
        return res;
    }
}
