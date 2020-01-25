package com.dezhonger.y2020.m01.d25;

import com.google.common.collect.Lists;

import java.util.Arrays;
import java.util.List;

/**
 * Created by dezhonger on 2020/01/25
 *
 * @author dezhonger
 * @since 2020/01/25
 */
public class Leetcode0638 {
    int res = Integer.MAX_VALUE;

    public static void main(String[] args) {
        int i = new Leetcode0638().shoppingOffers(Lists.newArrayList(2, 5),
                Lists.newArrayList(Lists.newArrayList(3, 0, 5), Lists.newArrayList(1, 2, 10)),
                Lists.newArrayList(3, 2));
        System.out.println(i);

    }

    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        int[] a = new int[price.size()];
        dfs(0, a, price, special, needs, 0);
        return res;
    }

    private void dfs(int index, int[] has, List<Integer> price, List<List<Integer>> special, List<Integer> needs, int p) {
        if (index == special.size()) {
            //加上不够的，更新总价格
            for (int i = 0; i < has.length; i++) {
                p += price.get(i) * (needs.get(i) - has[i]);
            }
            res = Math.min(res, p);
            return;
        }
        List<Integer> sp = special.get(index);
        for (int i = 0; ; i++) {
            int[] hasNew = Arrays.copyOf(has, has.length);
            int j;
            int danjia = sp.get(sp.size() - 1);
            for (j = 0; j < sp.size() - 1; j++) {
                hasNew[j] += i * sp.get(j);
            }
            if (check(hasNew, needs)) {
                dfs(index + 1, hasNew, price, special, needs, p + i * danjia);
            } else {
                break;
            }

        }
    }

    private boolean check(int[] hasNew, List<Integer> needs) {
        for (int i = 0; i < hasNew.length; i++) {
            if (hasNew[i] > needs.get(i)) return false;
        }
        return true;
    }
}
