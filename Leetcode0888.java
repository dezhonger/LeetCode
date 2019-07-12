
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by dezhonger on 2019/07/12
 *
 * @author dezhonger
 * @since 2019/07/12
 */
public class Leetcode0888 {
    public int[] fairCandySwap(int[] A, int[] B) {
        int sum1 = Arrays.stream(A).sum();
        int sum2 = Arrays.stream(B).sum();
        int diff = (sum1 - sum2) / 2;
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        Arrays.stream(A).forEach(s1::add);
        Arrays.stream(B).forEach(s2::add);
        for (int x : s1) {
            if (s2.contains(x - diff)) {
                return new int[]{x, x - diff};
            }
        }
        return null;
    }
}
