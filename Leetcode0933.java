package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2019/5/23
 */
public class Leetcode0933 {

    /**
     * Your RecentCounter object will be instantiated and called as such:
     * RecentCounter obj = new RecentCounter();
     * int param_1 = obj.ping(t);
     */
    public static void main(String[] args) {
        RecentCounter obj = new RecentCounter();
        int x;
        x = obj.ping(1);
        System.out.println(x);
        x = obj.ping(100);
        System.out.println(x);
        x = obj.ping(3001);
        System.out.println(x);
        x = obj.ping(3002);
        System.out.println(x);
    }
}


class RecentCounter {

    List<Integer> list = new ArrayList<>();

    public RecentCounter() {

    }

    public int ping(int t) {
        list.add(t);
        int index = find(t - 3000);
        return list.size() - index;
    }

    private int find(int t) {
        int l = 0;
        int r = list.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (list.get(mid) == t) return mid;
            if (list.get(mid) < t) l = mid + 1;
            else {
                r = mid;
            }
        }
        return l;
    }

}
