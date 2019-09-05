
/**
 * Created by dezhonger on 2019/9/5
 */
public class Leetcode1176 {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int r = 0;
        for (int i = 1; i < calories.length; i++) calories[i] += calories[i - 1];
        for (int i = k - 1; i < calories.length ;i++) {
            int t = calories[i] - i - k < 0 ? 0 : calories[i - k];
            if (t < lower) r--;
            if (t > upper) r++;
        }
        return r;
    }
}
