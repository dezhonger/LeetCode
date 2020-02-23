package com.netease.music.p20200223;

/**
 * Created by dezhonger on 2020/2/23
 */
public class Leetcode1095_2 {
    int len;
    MountainArray arr;
    int target;

    public int findInMountainArray(int target, MountainArray mountainArr) {
        this.len = mountainArr.length();
        this.arr = mountainArr;
        this.target = target;
        //二分找到山峰的位置
        int mid = findPeak();

        if (arr.get(mid) == target) return mid;
        //然后在两边分别搜索
        int lr = binary1(0, mid - 1);
        if (lr != -1) return lr;
        int rr = binary2(0, len - 1);
        return rr;
    }

    private int findPeak() {
        int l = 0;
        int r = len - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr.get(mid) < arr.get(mid + 1)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    private int binary1(int l, int r) {
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr.get(mid) == target) return mid;
            if (arr.get(mid) < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return arr.get(l) == target ? l : -1;
    }

    private int binary2(int l, int r) {
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr.get(mid) == target) return mid;
            if (arr.get(mid) < target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return arr.get(l) == target ? l : -1;
    }
}
