#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0208.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-13 00:03:29
//Last modified: 2021-05-13 00:12:26

const int N = 2000010;
int son[N][26], idx;
bool w[N];

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        idx = 0;
        memset(son, 0, sizeof son);
        memset(w, 0, sizeof w);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size(), p = 0;
        for (int i = 0; i < n; i++) {
            int c = word[i] - 'a';
            if (!son[p][c]) son[p][c] = ++idx;
            p = son[p][c];
        }
        w[p] = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size(), p = 0;
        for (int i = 0; i < n; i++) {
            int c = word[i] - 'a';
            if (!son[p][c]) return false;
            p = son[p][c];
        }
        return w[p];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size(), p = 0;
        for (int i = 0; i < n; i++) {
            int c = prefix[i] - 'a';
            if (!son[p][c]) return false;
            p = son[p][c];
        }
        return true;
    }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

