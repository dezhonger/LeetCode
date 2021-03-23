#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0749.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-03-23 13:21:00

typedef pair<int, int> PII;

class Solution {

#define F first
#define S second
	public:
		int n, m;
		vector<vector<int>> g;
		vector<vector<bool>> visit;
		vector<PII> path;
		set<PII> S;
		int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

		int dfs(int x, int y) {
			visit[x][y] = true;
			path.push_back({x, y});
			int res = 0;
			for (int i = 0; i < 4; i++) {
				int a = x + dx[i], b = y + dy[i];
				if (a >= 0 && b >= 0 && a < n && b < m) {
					if (!g[a][b]) S.insert({a, b}), res++;
					else if (g[a][b] == 1 && visit[a][b] == false) res += dfs(a, b);
				}	
			}
			return res;
		}

		int find() {
			visit = vector<vector<bool>>(n, vector<bool>(m));
			int cnt = 0, res = 0;
			//找到最大的感染的联通快
			vector<PII> ps;
			//记录所有的感染的联通块
			vector<set<PII>> ss;
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
				if (g[i][j] == 1 && !visit[i][j]) {
					path.clear(), S.clear();
					int t = dfs(i, j);
					if (S.size() > cnt) {
						cnt = S.size();
						res = t;
						ps = path;
					}
					ss.push_back(S);
				}
			}
			//加了防火墙的置为-1
			for (auto& p : ps) g[p.F][p.S] = -1;
			//把新感染的块置为1
			for (auto& s : ss) {
				if (s.size() != cnt) {
					for (auto& p : s) {
						g[p.F][p.S] = 1;
					}
				}
			}
			return res;
		}


		int containVirus(vector<vector<int>>& grid) {
			g = grid;
			n = g.size(), m = g[0].size();
			int res = 0;
			while (1) {
				int cnt = find();
				if (!cnt) break;
				res += cnt;
			}
			return res;
		}
};

int main() {
	ios::sync_with_stdio (false);
	cin.tie (0);
	return 0;
}

