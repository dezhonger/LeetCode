
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by zhangweilong on 2019/09/27
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/09/27
 */
public class Leetcode1202 {

    int[] father;


    int find(int x) {
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;
        father[fy] = fx;
    }

    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int len = s.length();
        father = new int[len];
        for (int i = 0; i < len; i++) father[i] = i;
        for (List<Integer> p : pairs) {
            int x = p.get(0);
            int y = p.get(1);
            merge(x, y);

        }
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < len; i++) {
            int f = find(i);
            List<Integer> integers = map.get(f);
            if (integers == null) {
                integers = new ArrayList<>();
                integers.add(i);
                map.put(f, integers);
            } else {
                integers.add(i);
            }
        }
        char[] r = new char[s.length()];

        map.forEach((k, v) -> {
            int l = v.size();
            char[] c = new char[l];
            for (int i = 0; i < l; i++) c[i] = s.charAt(v.get(i));
            Arrays.sort(c);
            Collections.sort(v);
            for (int i = 0; i < l; i++) {
                int index = v.get(i);
                r[index] = c[i];
            }
        });
        StringBuilder str = new StringBuilder();
        for (char c : r) str.append(c);
        return str.toString();
    }

}
