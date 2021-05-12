#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0329.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-13 00:40:20
//Last modified: 2021-05-13 00:48:22

class Solution {
public:
    vector<vector<int>> f;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int n, m;

    int dp(int i, int j, vector<vector<int>>& matrix) {
        if (f[i][j] != -1) return f[i][j];
        f[i][j] = 1;
        for (int d = 0; d < 4; d++) {
            int x = i + dx[d], y = j + dy[d];
            if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] < matrix[i][j]) {
                f[i][j] = max(f[i][j], dp(x, y, matrix) + 1);
            }
        }
        return f[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        f = vector<vector<int>>(n, vector<int>(m, -1));
        int res = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            res = max(res, dp(i, j, matrix));
        }
        return res;
    }
};



