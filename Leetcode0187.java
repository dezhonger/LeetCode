
import java.util.*;

/**
 * Created by Dezhonger on 2017/2/23.
 * 把String hash一下
 */
public class Leetcode0187 {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<Integer, Integer> mapset = new HashMap<>();
        Set<String> se = new HashSet<>();
        char[] map = new char[26];
        map['A' - 'A'] = 0;
        map['C' - 'A'] = 1;
        map['G' - 'A'] = 2;
        map['T' - 'A'] = 3;

        for(int i = 0; i < s.length() - 9; i++) {
            int v = 0;
            for(int j = i; j < i + 10; j++) {
                v <<= 2;
                v |= map[s.charAt(j) - 'A'];
            }
            if(!mapset.containsKey(v)) {
                mapset.put(v, 1);
            }  else {
                mapset.put(v, 2);
                se.add(s.substring(i, i + 10));
            }
        }
        return new ArrayList<String>(se);
    }
}
