package com.y2019.m12.d28.num692;

import com.y2018.m01.d09.T;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by zhangweilong on 2019/12/28
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/12/28
 */
public class Leetcode0692_BucketSort {
    //https://leetcode.com/problems/top-k-frequent-words/discuss/108399/Java-O(n)-solution-using-HashMap-BucketSort-and-Trie-22ms-Beat-81
    public List<String> topKFrequent(String[] words, int k) {
        List<String> res = new ArrayList<>();
        //统计单词出现个数
        Map<String, Integer> map = new HashMap<>();
        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }

        //建桶
        TrieBucket[] count = new TrieBucket[words.length + 1];

        for (String word : map.keySet()) {
            int freq = map.get(word);
            if (count[freq] == null) {
                count[freq] = new TrieBucket();
            }
            add(count[freq], word);
        }
        for (int f = count.length - 1; res.size() < k && f > 0; f--) {
            if (count[f] == null) continue;
            get(count[f], res, k);
        }
        return res;

    }

    private void get(TrieBucket root, List<String> res, int k) {
        if (root == null) return;
        if (root.word != null) res.add(root.word);
        if (res.size() == k) return;
        for (int i = 0; i < 26; i++) {
            if (root.next[i] != null) {
                get(root.next[i], res, k);
            }
        }
    }

    private void add(TrieBucket root, String word) {
        TrieBucket cur = root;
        for (char ch : word.toCharArray()) {
            if (cur.next[ch - 'a'] == null) {
                cur.next[ch - 'a'] = new TrieBucket();
            }
            cur = cur.next[ch - 'a'];
        }
        cur.word = word;
    }

    class TrieBucket {
        TrieBucket[] next;
        String word;

        public TrieBucket() {
            this.next = new TrieBucket[26];
            this.word = null;
        }
    }
}
