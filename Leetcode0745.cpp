#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0745.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-03-23 12:51:44

const int N = 2000000;//估计的 不够的话加大提交
int son[N][27], w[N], idx;


class WordFilter {
	public:

		void insert(string& s, int id) {
			int root = 0;
			for (auto c : s) {
				int t = c == '#' ? 26 : c - 'a';
				if (!son[root][t]) son[root][t] = ++idx;
				root = son[root][t];
				w[root] = id;
			}
		}

		int query(string s) {
			int root = 0;
			for (auto c : s) {
				int t = c == '#' ? 26 : c - 'a';
				if (!son[root][t]) return -1;
				root = son[root][t];
			}
			return w[root];
		}

		WordFilter(vector<string>& words) {
			memset(son, 0, sizeof son);
			idx = 0;
			for (int i = 0; i < words.size(); i++) {
				string s = '#' + words[i];
				for (int j = words[i].size() - 1; j >= 0; j--) {
					s = words[i][j] + s;
					insert(s, i);
				}
			}
		}

		int f(string prefix, string suffix) {
			return query(suffix + '#' + prefix);
		}
};

int main() {
	ios::sync_with_stdio (false);
	cin.tie (0);
	return 0;
}

