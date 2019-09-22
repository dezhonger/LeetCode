import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by dezhonger on 2019/09/23
 *
 * @author dezhonger
 * @since 2019/09/23
 */
public class Leetcode1200 {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int mi = Integer.MAX_VALUE;
        for (int i = 1; i < arr.length; i++) mi = Math.min(mi, arr[i] - arr[i - 1]);
        List<List<Integer>> r = new ArrayList<>();
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] -arr[i - 1] == mi) {
                List<Integer> tmp = new ArrayList<>();
                tmp.add(arr[i - 1]);
                tmp.add(arr[i]);
                r.add(tmp);
            }
        }
        return r;
    }

}
