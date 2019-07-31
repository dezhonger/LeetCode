
import java.util.Arrays;

/**
 * Created by zhangweilong on 2019/07/31
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/07/31
 */
public class Leetcode0910 {
    //贪心算法 contest103
    //https://zhanghuimeng.github.io/post/leetcode-910-smallest-range-ii/
    public int smallestRangeII(int[] A, int K) {
        Arrays.sort(A);
        //首先每个数都减去k
        for (int i = 0; i < A.length; i++) {
            A[i] -= K;
        }
        //接下来决定哪些数需要加k，由于之前已经减去了k，因此需要加上2k
        int ans = A[A.length - 1] - A[0];
        //尝试把第i个数之前的所有数都加上2k(包含第i个数)
        for (int i = 0; i < A.length - 1; i++) {
            //这样处理后最大可能值
            int ma = Math.max(A[A.length - 1], A[i] + 2 * K);
            //这样处理后最小可能值
            int mi = Math.min(A[0] + 2 * K, A[i + 1]);
            ans = Math.min(ans, ma - mi);
        }
        return ans;
    }
}
