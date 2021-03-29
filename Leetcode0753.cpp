#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0753.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-03-29 22:56:27

class Solution {
public:
	int n, k;
	string ans;
	set<string> ss;

	//欧拉回路
	void dfs(string s) {
		for (int i = 0; i < k; i++) {
			string nxt = s + to_string(i);
			if (!ss.count(nxt)) {
				ss.insert(nxt);
				dfs(nxt.substr(1));
				ans += to_string(i);
			}
		}
	}
    string crackSafe(int _n, int _k) {
        n = _n, k = _k;
		string s(n - 1, '0');
		dfs(s);
		return ans + s;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

