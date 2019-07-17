

import java.util.List;

/**
 * Created by dezhonger on 2019/7/17
 * trie
 */
public class Leetcode0648 {

    public String replaceWords(List<String> dict, String sentence) {
        Trie trie = new Trie();
        for (String word : dict) insert(trie, word);
        StringBuilder res = new StringBuilder();
        for (String word : sentence.split(" ")) {
            String tmp = findPrefix(trie, word);
            res.append(tmp);
            res.append(" ");
        }
        return res.toString().trim();
    }


    private void insert(Trie root, String word) {
        for (char c : word.toCharArray()) {
            if (root.children[c - 'a'] == null) root.children[c -'a'] = new Trie(c);
            root = root.children[c - 'a'];
        }
        root.isEnd = true;
    }

    private String findPrefix(Trie root, String word) {
        StringBuilder r = new StringBuilder();
        for (char c : word.toCharArray()) {
            Trie trie = root.children[c - 'a'];
            if (trie == null) break;
            r.append(c);
            root = trie;
            if (root.isEnd) return r.toString();
        }
        return word;
    }

    class Trie {
        char val;
        Trie[] children;
        boolean isEnd;

        public Trie() {
            children = new Trie[26];
            this.isEnd = false;
        }

        public Trie(char val) {
            this.val = val;
            children = new Trie[26];
            this.isEnd = false;
        }
    }
}
