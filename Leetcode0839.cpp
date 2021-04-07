#include <bits/stdc++.h>
using namespace std;



const int N = 310;
int fa[N];

class Solution {
public:
    int can(string s1, string s2) {
        int c = s1.size();
        vector<int> s;
        for (int i = 0; i < c; i++) {
            if (s1[i] != s2[i]) s.push_back(i);
        }
        if (s.size() == 0) return 1;
        if (s.size() != 2) return 0;
        int x = s[0], y = s[1];
        return s1[x] == s2[y] && s1[y] == s2[x];
    }
    
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    
    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) fa[fx] = fy;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        for (int i = 0; i < n; i++) fa[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (can(strs[i], strs[j])) merge(i, j);
            }
        }
        int ans = 0;
        //for (int i = 0; i < n; i++) cout << find(i) << " "; cout << endl;
        for (int i = 0; i < n; i++) if (find(i) == i) ans++;
        return ans;
    }
};

int main() {
    return 0;
}