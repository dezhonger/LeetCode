
import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2019/12/13
 */
public class Leetcode0423 {
    Map<Integer, String> map = new HashMap<>();

    public String originalDigits(String s) {
        map.put(0, "zero");
        map.put(1, "one");
        map.put(2, "two");
        map.put(3, "three");
        map.put(4, "four");
        map.put(5, "five");
        map.put(6, "six");
        map.put(7, "seven");
        map.put(8, "eight");
        map.put(9, "nine");
        int[] cnt = new int[26];
        int[] res = new int[10];
        for (char ch : s.toCharArray()) {
            cnt[ch - 'a']++;
        }

        //only zero have letter 'z'
        res[0] = cnt['z' - 'a'];
        remove(cnt, 0, res[0]);

        //only six have letter 'x'
        res[6] = cnt['x' - 'a'];
        remove(cnt, 6, res[6]);

        //only two have letter 'w'
        res[2] = cnt['w' - 'a'];
        remove(cnt, 2, res[2]);

        //only four have letter 'u'
        res[4] = cnt['u' - 'a'];
        remove(cnt, 4, res[4]);

        //then next only five have letter 'f', four have been calculate
        res[5] = cnt['f' - 'a'];
        remove(cnt, 5, cnt[5]);

        //only eight have letter 'g'
        res[8] = cnt['g' - 'a'];
        remove(cnt, 8, res[8]);

        res[7] = cnt['v' - 'a'];
        remove(cnt, 7, cnt[7]);

        res[9] = cnt['i' - 'a'];
        remove(cnt, 9, cnt[9]);


        res[1] = cnt['o' - 'a'];
        remove(cnt, 1, cnt[1]);

        res[3] = cnt['r' - 'a'];
        remove(cnt, 3, cnt[3]);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < res[i]; j++) sb.append((char)(i + '0'));
        }
        return sb.toString();
    }

    void remove(int[] cnt, int x, int c) {
        String s = map.get(x);
        for (char ch : s.toCharArray()) {
            cnt[ch - 'a'] -= c;
        }
    }
}
