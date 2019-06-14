
import java.util.HashSet;
import java.util.Set;

/**
 * Created by zhangweilong on 2019/06/14
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/06/14
 */
public class Leetcode1079 {
    int len;
    Set<String> set = new HashSet<>();
    private void dfs(int index, char[] c, boolean[] f, String str) {
        if (index == len) {
            set.add(str);
            return;
        }
        for (int k = 0; k < f.length; k++) {
            if (!f[k]) {
                f[k] = true;
                dfs(index + 1, c, f, str + c[k]);
                f[k] = false;
            }
        }
        dfs(index + 1, c, f, str);

    }

    public int numTilePossibilities(String tiles) {
        char[] chars = tiles.toCharArray();
        len = chars.length;
        boolean[] f = new boolean[len];
        dfs(0, chars, f, "");

        return set.size() - 1;
    }
}
