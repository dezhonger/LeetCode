
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * Created by dezhonger on 2019/7/16
 */
public class Leetcode0819 {

    public String mostCommonWord(String paragraph, String[] banned) {
        String[] split = paragraph.split(" |,|\\.|\\?|!|;|' ");
        Map<String, Integer> map = new HashMap<>();
        Set<String> set = Arrays.stream(banned).map(String::toLowerCase).collect(Collectors.toSet());
        for (String s : split) {
            s = s.toLowerCase();
            if (set.contains(s)) continue;
            if (s.equals("")) continue;
            map.put(s, map.getOrDefault(s, 0) + 1);
        }
        int integer = map.values().stream().max(Integer::compareTo).get();
        for (Map.Entry<String, Integer> m : map.entrySet()) {
            if (m.getValue() == integer) {
                return m.getKey();
            }
        }
        return null;
    }
}
