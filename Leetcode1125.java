
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dezhonger on 2019/7/15
 */
public class Leetcode1125 {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int s = req_skills.length;
        int n = people.size();
        int[] mask = new int[n];
        for (int i = 0; i < n; i++) {
            for (String skill : people.get(i)) {
                int index = -1;

                for (int j = 0; j < s; j++) {
                    if (skill.equals(req_skills[j])) {
                        index = j;
                        break;
                    }
                }
                if (index >= 0) mask[i] |= 1 << index;
            }
        }
        int[][] dp = new int[n + 1][1 << s];
        for (int i = 0; i <= n; i++) Arrays.fill(dp[i], 200000);
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int bit = 0; bit < 1 << s; bit++) {
                dp[i + 1][bit] = Math.min(dp[i + 1][bit], dp[i][bit]);
                dp[i + 1][bit | mask[i]] = Math.min(dp[i + 1][bit | mask[i]], dp[i][bit] + 1);
            }
        }
        int current = (1 << s) - 1;
        List<Integer> res = new ArrayList<>();
        for (int i = n - 1; i >= 0; i--) {
            int next_bit = -1;
            for (int m = 0; m < 1 << s; m++) {
                if ((current | m) == current && (m | mask[i]) == current && dp[i][m] + 1 == dp[i + 1][current]) {
                    next_bit = m;
                    break;
                }
            }
            if (next_bit >= 0) {
                res.add(i);
                current = next_bit;
            }
        }
        int[] r = new int[res.size()];
        for (int i = 0; i < r.length; i++) r[i] = res.get(r.length - 1 - i);
        return r;
    }
}
