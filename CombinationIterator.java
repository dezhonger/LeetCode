package com.y2019.m12.d15;

import com.y2018.m01.d11.Cal;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by zhangweilong on 2019/12/15
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/15
 */
public class CombinationIterator {

    String characters;
    int combinationLength;
    List<String> res = new ArrayList<>();
    int curIterator;

    public CombinationIterator(String characters, int combinationLength) {
        this.characters = characters;
        this.combinationLength = combinationLength;
        this.curIterator = 0;
        init();
    }

    private void init() {
        dfs(0, 0, "");
    }

    private void dfs(int cnt, int index, String str) {
        if (cnt == combinationLength) {
            res.add(str);
            return;
        }
        for (int i = index; i < characters.length(); i++) {
            dfs(cnt + 1, i + 1, str + characters.charAt(i));
        }
    }

    public String next() {
        return res.get(curIterator++);
    }

    public boolean hasNext() {
        return curIterator < res.size();
    }

}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator obj = new CombinationIterator(characters, combinationLength);
 * String param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
