#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0691.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-03 11:49:24
const int N = 1 << 15;
const int FFF = 1e6;
int dp[N];
class Solution {
	public:
	int n, m;
	vector<string> st;
	string tt;

	int fill(int state, char c) {
		int res = state;
		for (int i = 0; i < m; i++) {
			if ((state >> i & 1) == 0 && tt[i] == c) {
				res |= (1 << i);
				break;
			}
		}
		return res;
	}

	int dfs(int state) {
		if (dp[state] != -1) return dp[state];
		dp[state] = FFF;
		if (state == (1 << m) - 1) return dp[state] = 0;
		for (string& s : st) {
			int nxtState = state;
			for (int i = 0; i < s.size(); i++) {
				nxtState = fill(nxtState, s[i]);
			}
			if (nxtState == state) continue;
			dp[state] = min(dp[state], dfs(nxtState) + 1);
		}
		return dp[state];
	}
	int minStickers(vector<string>& stickers, string target) {
		n = stickers.size();
		m = target.size();
		st = stickers;
		tt = target;
		memset(dp, -1, sizeof dp);
		return dfs(0) == FFF ? -1 : dfs(0);
	}
};

int main() {
	ios::sync_with_stdio (false);
	cin.tie (0);
	return 0;
}

