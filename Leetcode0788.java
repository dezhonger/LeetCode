
import java.util.Arrays;

/**
 * Created by dezhonger on 2019/7/16
 */
public class Leetcode0788 {
    public int rotatedDigits(int N) {
        int r = 0;
        for (int i = 1; i <= N; i++) {
            if (check(i)) {
                r++;
                System.out.println(i);
            }
        }
        return r;
    }

    private boolean check(int i) {
        char[] map = new char[]{'0', '1', '5', 'z', 'z', '2', '9', 'z', '8', '6'};
        char[] chars = (i + "").toCharArray();
        char[] res = new char[chars.length];
        for (int i1 = 0; i1 < chars.length; i1++) {
            res[i1] = map[chars[i1] - '0'];
        }
        for (char re : res) {
            if (re == 'z') return false;

        }
        return !Arrays.equals(chars, res);
    }
}
