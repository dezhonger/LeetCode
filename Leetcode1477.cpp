#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1477.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-07 03:18:40
//Last modified: 2021-05-07 03:24:36

class Solution {
    public:

        int n, t;
        vector<int> f(vector<int> a) {
            unordered_map<int, int> mp;
            mp[0] = -1;
            int s = 0;
            vector<int> ans(n, INT_MAX / 3);
            for (int i = 0; i < n; i++) {
                s += a[i];
                if (i > 0) ans[i] = ans[i - 1];
                if (mp.count(s - t)) {
                    ans[i] = min(ans[i], i - mp[s - t]);
                }
                mp[s] = i;
            }
            return ans;
        }

        int minSumOfLengths(vector<int>& arr, int target) {
            n = arr.size(), t = target;
            vector<int> a1 = f(arr);
            reverse(arr.begin(), arr.end());
            vector<int> a2 = f(arr);
            reverse(a2.begin(), a2.end());
            int res = INT_MAX;
            for (int i = 0; i < n - 1; i++) {
                res = min(res, a1[i] + a2[i + 1]);
            }
            if (res > n) res = -1;
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

