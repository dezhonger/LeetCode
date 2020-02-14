package com.netease.music.p20200214;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by dezhonger on 2020/2/14
 */
public class Leetcode0464 {
    int maxNum;

    Map<Integer, Boolean> memory = new HashMap<>();

    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 <= desiredTotal) return false;
        this.maxNum = maxChoosableInteger;
        return cal(desiredTotal, (1 << maxChoosableInteger) - 1);
    }

    /**
     * 和为num的时候能选的数是can，先手是否能赢
     *
     * @param num
     * @param can
     * @return 1:win 2:false
     */
    private boolean cal(int num, int can) {
        int x = can * 100 + num;
        if (memory.containsKey(x)) return memory.get(x);
        for (int i = maxNum; i >= 1; i--) {
            if (((can >> (i - 1)) & 1) == 1) {
                if (num <= i) {
                    memory.put(x, true);
                    return true;
                }
                boolean c = cal(num - i, can ^ (1 << (i - 1)));
                //只要存在一种拿法，让后手输
                if (c == false) {
                    memory.put(x, true);
                    return true;
                }
            }
        }
        return false;
    }
}
