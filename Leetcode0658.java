package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2019/5/24
 */
public class Leetcode0658 {

    public static void main(String[] args) {
        List<Integer> closestElements = new Leetcode0658().findClosestElements(new int[]{1, 2, 3, 4, 5}, 4, 3);
        System.out.println(closestElements);
    }

    private int find(int[] arr, int k, int x) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] >= x) {
                if (i == 0) return 0;
                else {
                    int diff1 = Math.abs(arr[i - 1] - k);
                    int diff2 = Math.abs(arr[i] - k);
                    return diff1 < diff2 ? i - 1 : i;
                }
            }
        }
        return arr.length;
    }

    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int index = find(arr, k, x);
        List<Integer> list = new ArrayList<>();
        int j = k;
        if (index == arr.length) {
            for (int i = arr.length - 1; i >= 0 && j > 0; i--, j--) {
                list.add(arr[i]);
            }
        } else if (index == 0) {
            for (int i = 0; i < arr.length && j > 0; i++, j--) {
                list.add(arr[i]);
            }
        } else {
            list.add(arr[index]);
            int l = index - 1;
            int r = index + 1;
            j--;
            while (j > 0) {
                int diff1, diff2;
                diff1 = Integer.MAX_VALUE;
                diff2 = Integer.MAX_VALUE;
                if (l >= 0) {
                    diff1 = Math.abs(arr[l] - x);
                }
                if (r < arr.length) {
                    diff2 = Math.abs(arr[r] - x);
                }

                if (diff1 <= diff2) {
                    list.add(arr[l]);
                    l--;
                } else {
                    list.add(arr[r]);
                    r++;
                }
                j--;
            }
        }
        Collections.sort(list);
        return list;
    }
}
