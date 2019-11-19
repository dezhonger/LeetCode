
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2019/11/20
 *
 * @author dezhonger
 * @since 2019/11/20
 */
public class Leetcode1262 {

    public int maxSumDivThree(int[] nums) {
        List<Integer> mod1 = new ArrayList<>();
        List<Integer> mod2 = new ArrayList<>();
        int sum = 0;
        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) mod1.add(x);
            else if (x % 3 == 2) mod2.add(x);
        }
        if (sum % 3 == 0) return sum;
        Collections.sort(mod1);
        Collections.sort(mod2);
        int res = 0;
        if (sum % 3 == 1) {
            if (mod1.size() >= 1) {
                res = Math.max(res, sum - mod1.get(0));
            }
            if (mod2.size() >= 2) {
                res = Math.max(res, sum - mod2.get(0) - mod2.get(1));
            }
            return res;
        } else {
            if (mod1.size() >= 2) {
                res = Math.max(res, sum - mod1.get(0) - mod1.get(1));
            }
            if (mod2.size() >= 1) {
                res = Math.max(res, sum - mod2.get(0));
            }
            return res;
        }
    }
}
