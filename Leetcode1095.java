package com.netease.music.p20200223;

interface MountainArray {
    int get(int index);

    int length();
}

/**
 * Created by dezhonger on 2020/2/23
 */
public class Leetcode1095 {
    int len;
    MountainArray arr;
    int target;

    public int findInMountainArray(int target, MountainArray mountainArr) {
        this.len = mountainArr.length();
        this.arr = mountainArr;
        this.target = target;
        //这个数组有极大值，我们先三分找到极大值
        int mid = findPeak();

        if (arr.get(mid) == target) return mid;
        //然后在两边分别搜索
        int lr = binary1(0, mid - 1);
        if (lr != -1) return lr;
        int rr = binary2(0, len - 1);
        return rr;
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

    int findPeak() {
        int l = 0;
        int r = len - 1;
        while (r - l > 2) {
            int lmid = l + (r - l) / 3;
            int rmid = r - (r - l) / 3;
            int lv = arr.get(lmid);
            int rv = arr.get(rmid);
            if (lv <= rv) {
                l = lmid + 1;
            } else {
                r = rmid - 1;
            }
        }
        int ma = arr.get(l);
        int idx = l;
        for (int i = l + 1; i <= r; i++) {
            int v = arr.get(i);
            if (v > ma) {
                ma = v;
                idx = i;
            }
        }
        return idx;
    }
}
