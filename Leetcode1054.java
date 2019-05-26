package com.netease.music.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by dezhonger on 2019/5/26
 */
public class Leetcode1054 {
    public int[] rearrangeBarcodes(int[] barcodes) {
        int[] cnt = new int[10001];
        for (int x : barcodes) cnt[x]++;
        int[] r = new int[barcodes.length];
        List<Pa> list = new ArrayList<>();
        for (int i = 1; i <= 10000; i++) {
            if (cnt[i] > 0) {
                list.add(new Pa(i, cnt[i]));
            }
        }
        Collections.sort(list);
        int index = 0;
        int i = 0;
        while (true) {
            if (index == list.size()) break;

            Pa pa = list.get(index);
            index++;
            int val = pa.val;
            int c = pa.c;

            for (; i < r.length && c > 0; i += 2) {
                r[i] = val;
                c--;
            }
            if (c > 0) {
                i = 1;
                for (; i < r.length && c > 0; i += 2) {
                    r[i] = val;
                    c--;
                }
            }

        }
        return r;
    }

    class Pa implements Comparable<Pa> {


        Pa(int val, int c) {
            this.val = val;
            this.c = c;
        }

        int val;
        int c;

        @Override
        public int compareTo(Pa o) {
            return Integer.compare(o.c, c);
        }
    }

}
