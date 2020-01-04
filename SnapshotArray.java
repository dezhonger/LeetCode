package com.y2020.m01.d04;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by zhangweilong on 2020/01/04
 *
 * @author zhangweilong@corp.netease.com
 * @since 2020/01/04
 * leetcode 1146
 */
public class SnapshotArray {

    List<int[]>[] his;
    int time;

    public SnapshotArray(int length) {
        his = new ArrayList[length];
        for (int i = 0; i < length; i++) {
            his[i] = new ArrayList<>();
            //预处理
            his[i].add(new int[]{0, 0});
        }
        time = 0;
    }

    public void set(int index, int val) {
        if (his[index].get(his[index].size() - 1)[0] == time) {
            //覆盖
            his[index].get(his[index].size() - 1)[1] = val;
        } else {
            //新增
            his[index].add(new int[]{time, val});
        }
    }

    public int snap() {
        return time++;
    }

    public int get(int index, int snap_id) {
        int l = 0;
        int r = his[index].size() - 1;
        if (snap_id >= his[index].get(r)[0]) {
            return his[index].get(r)[1];
        }

        //不变式是 snap_id 满足 his[index].get(r)[l] < snap_id < his[index].get(r)[0]
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int x = his[index].get(mid)[0];
            if (x == snap_id) return his[index].get(mid)[1];
            else if (x < snap_id) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return his[index].get(l)[1];
    }
}
