

/**
 * Created by dezhonger on 2019/03/29
 *
 * @author dezhonger
 * @since 2019/03/29
 */
public class Leetcode0918 {

    public static void main(String[] args) {
        Leetcode0918 leetcode = new Leetcode0918();
//        System.out.println(leetcode.maxSubarraySumCircular(new int[]{1, -2, 3, -2})); //3
//        System.out.println(leetcode.maxSubarraySumCircular(new int[]{5,-3,5})); //10,
//        System.out.println(leetcode.maxSubarraySumCircular(new int[]{3,-1,2,-1})); //4
        System.out.println(leetcode.maxSubarraySumCircular(new int[]{-1, -2, -3})); //4
    }

    public int maxSubarraySumCircular(int[] A) {

        int max = A[0];
        int min = A[0];
        int atMax = A[0];
        int atMin = A[0];
        int s = A[0];
        for (int i = 1; i < A.length; i++) {
            int x = A[i];
            s += x;
            atMax = Math.max(x, atMax + x);
            atMin = Math.min(x, atMin + x);
            max = Math.max(max, atMax);
            min = Math.min(min, atMin);
        }

        if (max < 0) {
            //边界处理，所有的数都小于0的时候
            return max;
        }
        return Math.max(max, s - min);

    }

}
