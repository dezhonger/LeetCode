#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0354.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-14 02:46:36
//Last modified: 2021-05-14 03:07:16

class Solution {
    public:
        int n;
        vector<int> f;

        int maxEnvelopes(vector<vector<int>>& envelopes) {
            n = envelopes.size();
            f = vector<int>(n, 1);
            sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
                    if (a[0] != b[0]) return a[0] < b[0];
                    return a[1] < b[1];
                    });
            int res = 1;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                        f[i] = max(f[i], f[j] + 1);
                    }
                    res = max(res, f[i]);
                }
            }
            return res;
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

