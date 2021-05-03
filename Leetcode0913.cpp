#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0913.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-03 22:20:52
//Last modified: 2021-05-03 22:34:48

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

class Solution {
public:
	int n;
	vector<vector<vector<int>>> dp;
	vector<vector<int>> g;

	int dfs(int t, int x, int y) {
		//如果步数已经超过2n步，认为是平局。不会证明，感性理解一下
		if (t > 2 * n) return 0;
		if (dp[t][x][y] != -1) return dp[t][x][y];
		//在洞里，老鼠win
		if (x == 0) return 1;
		//位置相同，猫win
		if (x == y) return 2;
		if (t % 2 == 0) {
			//下一步是老鼠移动
			bool draw = false;
			for (int m: g[x]) {
				int res = dfs(t + 1, m, y);
				if (res == 1) return dp[t][x][y] = 1;
				//老鼠有办法走到平局
				if (res == 0) draw = true;
			}
			if (draw) dp[t][x][y] = 0;
			else dp[t][x][y] = 2;
		} else {
			//下一步是猫移动
			bool draw = false;
			for (int m: g[y]) {
				if (m == 0) continue;
				int res = dfs(t + 1, x, m);
				if (res == 2) return dp[t][x][y] = 2;
				if (res == 0) draw = true;
			}
			if (draw) dp[t][x][y] = 0;
			else dp[t][x][y] = 1;
		}
		return dp[t][x][y];
	}

    int catMouseGame(vector<vector<int>>& graph) {
		n = graph.size();
		g = graph;
		dp = vector<vector<vector<int>>>(2 * n + 1, vector<vector<int>>(n, vector<int>(n, -1))); 
		//dp[t][x][y]: 当前是第t步，老鼠在位置x，猫在位置y的结果. 0: 平局 1:老鼠win 2:猫win
		return dfs(0, 1, 2);
    }
};

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

