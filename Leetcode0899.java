
import java.util.Arrays;

/**
 * Created by dezhonger on 2019/07/19
 *
 * @author dezhonger
 * @since 2019/07/19
 */
public class Leetcode0899 {
    public String orderlyQueue(String S, int K) {
        if (K > 1) {
            char[] cs = S.toCharArray();
            Arrays.sort(cs);
            return new String(cs);
        } else {
            int len = S.length();
            S = S + S;
            String res =S;
            for (int i = 0; i < len; i++ ) {
                String sub = S.substring(i, i + len);
                if (sub.compareTo(res) < 0) res = sub;

            }
            return res;
        }
    }

}
