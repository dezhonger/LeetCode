#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1786.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//spfa求最短路，然后递推求解
//Create: 2021-03-07 13:13:27

#define PII  pair<int, int>

#define F first
#define S second

class Solution {
	public:
		const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

		vector<vector<PII>> g;// graph
		vector<int> dist;//最短路距离
		vector<int> f; //每个点到n的满足条件的路径个数
		vector<bool> st; //spfa使用

		int countRestrictedPaths(int n, vector<vector<int>>& edges) {
			g.resize(n + 1);
			dist.resize(n + 1, INF);
			f.resize(n + 1);
			st.resize(n + 1);

			for (auto& e: edges) {
				int a = e[0], b = e[1], w = e[2];
				g[a].push_back({b, w});
				g[b].push_back({a, w});
			}
			
			//spfa
			queue<int> q;
			q.push(n);
			dist[n] = 0;
			while (q.size()) {
				auto t = q.front();
				q.pop();
				st[t] = false;

				for(auto& p: g[t]) {
					int nxtNode = p.F, w = p.S;
					if (dist[nxtNode] > dist[t] + w) {
						dist[nxtNode] = dist[t] + w;
						if (!st[nxtNode]) {
							st[nxtNode] = true;
							q.push(nxtNode);
						}
					}
				}
			}

			//仿照拓扑图的顺序递推求解
			vector<PII> vs;
			for (int i = 1; i <= n; i++) vs.push_back({dist[i], i});
			sort(vs.begin(), vs.end());
			f[n] = 1;
			for (auto& v : vs) {
				int d = v.F, node = v.S;
				//枚举从node的所有边
				for (auto& e: g[node]) {
					int nxtNode = e.F;
					//需要满足题目的受限路径条件
					if (d > dist[nxtNode]) f[node] = (f[node] + f[nxtNode]) % MOD;
				}
			}
			return f[1];

		}
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

