#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0174.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-14 21:00:30
//Last modified: 2021-05-14 21:10:38

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> f(n, vector<int>(m, 1e8));
        //f[i][j] 从[i, j]达到终点需要最少的血量值
        int c = dungeon[n - 1][m - 1];
        f[n - 1][m - 1] = c > 0 ? 1 : 1 - c;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i + 1 < n) {
                    //f[i][j] + d[i][j] >= f[i + 1][j]
                    f[i][j] = min(f[i][j], max(1, f[i + 1][j] - dungeon[i][j]));
                }
                if (j + 1 < m) {
                    f[i][j] = min(f[i][j], max(1, f[i][j + 1] - dungeon[i][j]));
                }
            }
        }
        return f[0][0];
    }
};


