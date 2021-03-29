#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0741.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-03-29 23:24:37

const int N = 55;
int f[N][N][N * 2];
class Solution {
	public:
	int cherryPickup(vector<vector<int>>& g) {
		memset(f, 0xc0, sizeof f); //赋一个较小值，注意不是极小值，极小值是0x80

		int n = g.size();
		if (g[0][0] != -1) f[1][1][2] = g[0][0];
		for (int k = 3; k <= 2 * n; k++) {
			//k - i <= n, i >= k - n
			for (int i = max(1, k - n); i <= min(n, k - 1); i++) {
				for (int j = max(1, k - n); j <= min(n, k - 1); j++) {
					//g的坐标从0开始，所以要减去1
					if (g[i - 1][k - i - 1] == -1 || g[j - 1][k - j - 1] == -1) continue;
					int t = g[i - 1][k - i - 1];
					if (i != j) t += g[j - 1][k - j - 1];
					for (int x = i - 1; x <= i; x++) for (int y = j - 1; y <= j; y++) {
						f[i][j][k] = max(f[i][j][k], f[x][y][k - 1] + t);
					}
				}
			}
		}
		return max(0, f[n][n][2 * n]);
	}
};

int main() {
	ios::sync_with_stdio (false);
	cin.tie (0);
	return 0;
}

