#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0924.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-23 02:42:11

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
const double euler_r = 0.57721566490153286060651209;
const double pi = 3.141592653589793238462643383279;
const double E = 2.7182818284590452353602874713526;
const int inf = ~0U >> 1;
const int mod = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 310;
class Solution {
	public:
		int v[N];
		set<int> s;
		int c1, c0, n;
		
		void dfs(int i, vector<vector<int>>& g, int x) {
			v[i] = 1;
			if (s.count(i)) c1++;
			else c0++;
			for (int k = 0; k < n; k++) {
				if (k == i || k == x) continue;
				if (g[i][k] == 1 && v[k] == 0) {
					dfs(k, g, x);
				}
			}
		}

		int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
			n = graph.size();
			s.clear();
            sort(initial.begin(), initial.end());
			for (int x: initial) s.insert(x);
			map<int, int> mp;
			for (int i = 0; i < initial.size(); i++) {
				int x = initial[i];
				c0 = c1 = 0;
				CLR(v, 0);
				int ganran = 0;
				for (int j = 0; j < initial.size(); j++) {
					c0 = c1 = 0;
					if (j == i) continue;
                    if (v[initial[j]]) continue;
					dfs(initial[j], graph, x);
					ganran += c0 + c1;
				}
				mp[x] = ganran;
                //cout << x << " " << ganran << endl;
			}
			int maxV = INT_MAX;
			int ans = -1;
			for (auto [k, v]: mp) {
				if (v < maxV) ans = k, maxV = v;
			}
			return ans;
		}
};



