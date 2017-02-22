package leetcode;

/**
 * Created by Dezhonger on 2017/2/22.
 * 在一个旋转过的数组中寻找一个特定值
 * 如果a[l] < a[r]， 直接二分查到
 * 否则在两边递归下去
 */
public class Leetcode033 {

    public int f(int l, int r, int[] num, int t) {
        if(l > r) return -1;
        if(l == r) return num[l] == t ? l : -1;
        int a = l;
        int b = r;
        if(num[a] < num[b]){
            while(a <= b) {
                int mid = (a + b) / 2;
                if(num[mid] < t) {
                    a = mid + 1;
                } else if(num[mid] > t) {
                    b = mid - 1;
                } else {
                    return mid;
                }
            }
            return -1;
        } else {
            int mid = (a + b) / 2;
            if(num[mid] == t) {
                return mid;
            }
            int ans1 = f(l, mid - 1, num, t);
            int ans2 = f(mid + 1, r, num, t);
            return Math.max(ans1, ans2);
        }
    }

    public int search(int[] nums, int target) {
        int len = nums.length;
        if(nums == null || len == 0) {
            return -1;
        }
        int l = 0;
        int r = len - 1;
        return f(l, r, nums, target);
    }
}
