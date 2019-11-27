
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * Created by dezhonger on 2019/11/27
 *
 * @author dezhonger
 * @since 2019/11/27
 */
public class Leetcode1224 {
    public static void main(String[] args) {
        System.out.println(new Leetcode1224().maxEqualFreq(new int[]{1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5}));//13
        System.out.println(new Leetcode1224().maxEqualFreq(new int[]{1, 2, 3, 4}));//4
        System.out.println(new Leetcode1224().maxEqualFreq(new int[]{1, 1, 1, 2, 2, 2}));//5
        System.out.println(new Leetcode1224().maxEqualFreq(new int[]{2, 2, 1, 1, 5, 3, 3, 5}));//7
        System.out.println(new Leetcode1224().maxEqualFreq(new int[]{10, 2, 8, 9, 3, 8, 1, 5, 2, 3, 7}));//8
        System.out.println(new Leetcode1224().maxEqualFreq(new int[]{1, 2, 3, 1, 2, 3, 4, 4, 4, 4, 1, 2, 3, 5, 6}));//13
        System.out.println(new Leetcode1224().maxEqualFreq(new int[]{1, 1}));//2
        System.out.println(new Leetcode1224().maxEqualFreq(new int[]{1, 2, 2, 2, 2, 2, 82, 91, 27, 25, 1,}));//6

    }

    void add(Map<Integer, List<Integer>> map, int cnt, int a) {
        if (cnt > 0) {
            List<Integer> orDefault = map.getOrDefault(cnt, new ArrayList<>());
            orDefault.add(a);
            map.put(cnt, orDefault);
        }
    }

    void minus(Map<Integer, List<Integer>> map, int cnt, int a) {
        if (cnt > 0) {
            List<Integer> orDefault = map.getOrDefault(cnt, new ArrayList<>());
            orDefault.remove((Integer) a);
        }
    }


    public int maxEqualFreq(int[] nums) {
        int M = 100010;
        //每个数出现的次数
        int[] cnt = new int[M];
        //每个次数对应的个数
        int[] p = new int[M];
        //key:出现次数，出现这个次数的是那些数
        Map<Integer, List<Integer>> map = new HashMap<>();

        for (int x : nums) {
            cnt[x]++;
        }
        for (int i = 0; i < cnt.length; i++) {
            p[cnt[i]]++;
            add(map, cnt[i], i);
        }

        //一共有多少个次数
        int q = 0;
        for (int i = 1; i < p.length; i++) {
            if (p[i] > 0) {
                q++;
            }
        }


        for (int i = nums.length - 1; i >= 0; i--) {
            //只有一种次数
            if (q == 1) {
                List<Integer> collect = map.keySet().stream().collect(Collectors.toList());
                List<Integer> list = map.get(collect.get(0));
                //要么所有数都出现了一次，要么只有一个数出现了N次
                if (cnt[list.get(0)] == 1 || list.size() == 1) {
                    return i + 1;
                }
            }

            //有两种次数
            if (q == 2) {
                List<Integer> collect = new ArrayList<>();
                map.forEach((k, v) -> {
                    if (v.size() > 0) collect.add(k);
                });

                List<Integer> list1 = map.get(collect.get(0));
                List<Integer> list2 = map.get(collect.get(1));
                int c1 = list1.size();
                int c2 = list2.size();
                //出现一种次数的对应那个数，找到它，要么它出现了一次(111222 3, 删掉3)，要么他比另外次数的那个多了一次(111222333 4444, 删掉4)
                if (c1 == 1) {
                    if (list1.size() == 1 && (cnt[list1.get(0)] - 1 == cnt[list2.get(0)] || cnt[list1.get(0)] == 1)) {
                        return i + 1;
                    }
                }
                if (c2 == 1) {
                    if (list2.size() == 1 && (cnt[list2.get(0)] - 1 == cnt[list1.get(0)] || cnt[list2.get(0)] == 1)) {
                        return i + 1;
                    }
                }
            }

            int x = nums[i];
            cnt[x]--;
            p[cnt[x] + 1]--;
            minus(map, cnt[x] + 1, x);
            if (p[cnt[x] + 1] == 0) {
                q--;
            }
            p[cnt[x]]++;
            add(map, cnt[x], x);
            if (p[cnt[x]] == 1) {
                q++;
            }
        }
        return 0;
    }
}
