#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0126.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-11 01:19:33
//Last modified: 2021-05-11 01:37:27

class Solution {
public:
    string s, e;
    vector<vector<string>> ans;
    unordered_map<string, int> dis;
    set<string> st;
    unordered_set<string> S;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        s = beginWord, e = endWord;
        for (string& ss: wordList) S.insert(ss);
        S.insert(s);
        queue<string> q;
        dis[s] = 0;
        st.insert(s);
        q.push(s);

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur == e) break;
            string t = cur;
            for (int i = 0; i < t.size(); i++) {
                string tt = t;
                for (int j = 0; j < 26; j++) {
                    tt[i] = j + 'a';
                    if (S.count(tt) && st.count(tt) == 0) {
                        //在单词列表里，且没有没搜过
                        q.push(tt);
                        dis[tt] = dis[cur] + 1;
                        st.insert(tt);
                    }
                }
            }
        }


        cout << dis[e] << endl;
        //没有结果
        if (dis.count(e) == 0) return ans;

        vector<string> p;
        p.push_back(e);
        getPath(p, e);
        return ans;
    }

    void getPath(vector<string> p, string last) {
        if (last == s) {
            reverse(p.begin(), p.end());
            ans.push_back(p);
            reverse(p.begin(), p.end());
            return ;
        } 

        for (int i = 0; i < last.size(); i++) {
            string t = last;
            for (int j = 0; j < 26; j++) {
                t[i] = j + 'a';
                if (S.count(t) && dis.count(t) && dis[t] + 1 == dis[last]) {
                    p.push_back(t);
                    getPath(p, t);
                    p.pop_back();
                }
            }
        }

    }
};

int main() {
    Solution s;
    vector<string> v = {"hot","dot","dog","lot","log","cog"};
    s.findLadders("hit", "cog", v);
    return 0;
}

