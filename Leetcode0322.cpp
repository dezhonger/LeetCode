#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0322.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-13 00:34:17
//Last modified: 2021-05-13 00:39:24


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MAXV = 1000000;
        vector<int> f(amount + 1, MAXV);
        f[0] = 0;
        int m = coins.size();
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < m; j++) {
                if (i >= coins[j]) f[i] = min(f[i], f[i - coins[j]] + 1);
            }
        }
        return f[amount] == MAXV ? -1 : f[amount];
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

