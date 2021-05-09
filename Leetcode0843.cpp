#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0843.cpp
//核心思路是如果调用master.guess(word)后的值为ans,那么答案就是说word和secret的匹配个数是ans,不符合这个条件的单词就都被排除掉了
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-10 00:45:39
//Last modified: 2021-05-10 01:05:48

 class Master {
   public:
     int guess(string word);
 };

const int sz = 6;
 
class Solution {
public:
    int n;
    vector<vector<int>> f;
    vector<string> w;
    vector<int> st;

    void cal(vector<string> &w) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = 0;
                for (int k = 0; k < sz; k++) {
                    if (w[i][k] == w[j][k]) x++;
                }
                f[i][j] = x;
            }
        }
    }

    int get(int i, int u) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (!st[j] && f[i][j] == u) c++;
        }
        return c;
    }

    void findSecretWord(vector<string>& w, Master& master) {
        n = w.size();
        f = vector<vector<int>>(n, vector<int>(n, 0));
        st = vector<int>(n, 0);
        cal(w);

        int cc = 10;

        while (cc--) {
            //尝试枚举猜每个单词以及返回值为所有的情况的时候可以排除掉的结果数量
            int a = -1, b = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (st[i]) continue;
                int d = 0;
                //假设来猜第i个单词, 以及master.guess(w[i]))的返回值是u
                for (int u = 0; u < sz; u++) {
                    int cnt = get(i, u);
                    d = max(d, cnt);
                }
                if (d < b) b = d, a = i;
            }
            int res = master.guess(w[a]);
            if (res == sz) return ;
            for (int i = 0; i < n; i++) {
                if (!st[i] && f[a][i] != res) st[i] = true;
            }
        }
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

