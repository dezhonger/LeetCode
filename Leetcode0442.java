package leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Dezhonger on 2017/2/22.
 * 有的数出现两次有的出现一次，找出出现两次的数
 * 做法：当前数一次，则它作为下表对应的那个数自己乘以-1
 */
public class Leetcode0442 {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        for(int x : nums) {
            int index = Math.abs(x) - 1;
            if(nums[index] < 0) {
                ans.add(Math.abs(x));
            }
            nums[index] *= -1;
        }
        return ans;
    }
}
