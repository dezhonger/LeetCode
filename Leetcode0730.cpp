#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0730.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-03-29 23:56:31

#define pb push_back
const int MOD = 1000000007;
const int N = 1010;
class Solution {
public:
	int f[N][N];
    int countPalindromicSubsequences(string S) {
		int n = S.size();
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) f[i][j] = 1;
		for (int i = 0; i < n; i++) {
			//包含空串
			f[i][i] = 2;
		}
		for (int len = 2; len <= n; len++) {
			deque<int> ch[4];
			for (int i = 0; i < len - 1; i++) ch[S[i] - 'a'].pb(i);
			for (int i = 0; i + len - 1 < n; i++) {
				int j = i + len - 1;
				ch[S[j] - 'a'].pb(j);
				for (int k = 0; k < 4; k++) {
					if (ch[k].size() > 0) {
						f[i][j]++;//先加上单独一个字母形成的回文串
						int l = ch[k].front(), r = ch[k].back();
						if (l < r) f[i][j] = (f[i][j] + f[l + 1][r - 1]) % MOD;
					}
				}
				ch[S[i] - 'a'].pop_front();
			}
		}
		return (f[0][n - 1] - 1 + MOD) % MOD;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

