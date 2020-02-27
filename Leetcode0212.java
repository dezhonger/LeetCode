package com.netease.music.p20200228;

import com.google.common.collect.Lists;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Created by dezhonger on 2020/2/28
 */
public class Leetcode0212 {

    Set<String> res = new HashSet<>();
    int[] dx = new int[]{-1, 0, 1, 0};
    int[] dy = new int[]{0, 1, 0, -1};
    int m, n;

    public static void main(String[] args) {
        Leetcode0212 sol = new Leetcode0212();
        System.out.println(sol.findWords(new char[][]{
                {'o', 'a', 'a', 'n'},
                {'e', 't', 'a', 'e'},
                {'i', 'h', 'k', 'r'},
                {'i', 'f', 'l', 'v'}
        }, new String[]{"oath", "pea", "eat", "rain"}));
    }

    public List<String> findWords(char[][] board, String[] words) {
        TrieNode root = new TrieNode();
        for (String word : words) {
            build(root, word);
        }
        m = board.length;
        n = board[0].length;
        boolean[] v = new boolean[m * n];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (root.children[board[i][j] - 'a'] == null) continue;
                v[i * n + j] = true;
                dfs(i, j, board, root.children[board[i][j] - 'a'], board[i][j] + "", v);
                v[i * n + j] = false;
            }
        }

        return new ArrayList<>(res);
    }

    private void dfs(int i, int j, char[][] board, TrieNode root, String word, boolean[] v) {
        if (root.w == true) {
            res.add(word);
        }

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < board.length && y >= 0 && y < board[0].length) {
                int nxt = board[x][y] - 'a';
                if (root.children[nxt] == null) continue;
                if (v[x * n + y]) continue;
                v[x * n + y] = true;
                dfs(x, y, board, root.children[nxt], word + board[x][y], v);
                v[x * n + y] = false;
            }
        }

    }

    private void build(TrieNode r, String word) {
        TrieNode root = r;
        char[] ch = word.toCharArray();
        for (int i = 0; i < ch.length; i++) {
            int t = ch[i] - 'a';
            if (root.children[t] == null) {
                root.children[t] = new TrieNode();
            }
            root = root.children[t];
        }
        root.w = true;
    }
    class TrieNode {

        TrieNode[] children;
        boolean w;

        public TrieNode() {
            this.children = new TrieNode[26];
            this.w = false;
        }
    }



}


