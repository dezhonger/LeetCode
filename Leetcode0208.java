

/**
 * Created by zhangweilong on 2019/09/18
 *
 * @author zhangweilong@corp.netease.com
 * @since 2019/09/18
 */
public class Leetcode0208 {

    Tri root;

    /**
     * Initialize your data structure here.
     */
    public Leetcode0208() {
        root = new Tri();
    }

    /**
     * Inserts a word into the trie.
     */
    public void insert(String word) {
        insert(root, word);
    }


    /**
     * Returns if the word is in the trie.
     */
    public boolean search(String word) {
        Tri tri = root;
        for (char c : word.toCharArray()) {
            tri = tri.children[c - 'a'];
            if (tri == null) return false;
        }
        return tri.isEnd;
    }

    /**
     * Returns if there is any word in the trie that starts with the given prefix.
     */
    public boolean startsWith(String prefix) {
        Tri tri = root;
        for (char c : prefix.toCharArray()) {
            tri = tri.children[c - 'a'];
            if (tri == null) return false;
        }
        return true;
    }

    private void insert(Tri root, String word) {
        for (char c : word.toCharArray()) {
            if (root.children[c - 'a'] == null) root.children[c - 'a'] = new Tri(c);
            root = root.children[c - 'a'];
        }
        root.isEnd = true;
    }


    class Tri {
        char val;
        Tri[] children;
        boolean isEnd;

        public Tri() {
            children = new Tri[26];
            this.isEnd = false;
        }

        public Tri(char val) {
            this.val = val;
            children = new Tri[26];
            this.isEnd = false;
        }
    }
}



