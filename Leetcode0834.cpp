#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0834.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-20 00:59:04

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define each(x,y) for(auto y = x.begin(); y != x.end(); y++) cout << *y << " "; cout << endl;

#define Debug(x) cout<<#x<<"="<<x<<endl;
typedef long long LL;

const int N = 10010;
class Solution {
	public:
		int h[N], e[N << 1], ne[N << 1], idx;
		int dp[N], sz[N];

		void add(int a, int b) {
			e[idx] = b, ne[idx] = h[a], h[a] = idx++;
		}

		void dfs(int v, int fa) {
			dp[v] = 0, sz[v] = 1;
			for (int i = h[v]; ~i; i = ne[i]) {
				int u = e[i];
				if (u == fa) continue;
				dfs(u, v);
				sz[v] += sz[u];
				dp[v] += dp[u];
				dp[v] += sz[u];
			}
		}

		void dfs(int v, int fa, vector<int>& r) {
			//cout << v << " " << fa << " " << dp[v] << endl;
			r[v] = dp[v];
			for (int i = h[v]; ~i; i = ne[i]) {
				int u = e[i];
				if (u == fa) continue;
				int olddpv = dp[v];
				int oldszv = sz[v];
				int olddpu = dp[u];
				int oldszu = sz[u];
				//进行换根操作，把u变为根. 换根只影响u和v的 sz和dp值
                dp[v] = olddpv - olddpu - oldszu;
                sz[v] = oldszv - oldszu;
                
                sz[u] = oldszu + sz[v];
				dp[u] = olddpu + sz[v] + dp[v];
				
				
				
				dfs(u, v, r);
				dp[u] = olddpu;
				dp[v] = olddpv;
				sz[u] = oldszu;
				sz[v] = oldszv;
			}
		}

		vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
			idx = 0;
			memset(dp, 0, sizeof dp);
			memset(sz, 0, sizeof sz);
			memset(h, -1, sizeof h);
			for (auto x : edges) {
				int a = x[0], b = x[1];
				add(a, b), add(b, a);
			}
			dfs(0, -1);
			vector<int> r(N);
			dfs(0, -1, r);
			return r;

		}
};

