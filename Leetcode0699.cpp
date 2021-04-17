#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode699.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-17 20:09:24

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
	vector<int>	v;
	int height[2020];
	inline int query(int x) {
		return lower_bound(v.begin(), v.end(), x) - v.begin();
	}

	int query(int l, int r) {
		int ans = 0;
		for (int i = l; i <= r; i++)	ans = max(ans, height[i]);
		return ans;
	}

	void update(int l, int r, int h) {
		for (int i = l; i <= r; i++) height[i] = h;
	}

    vector<int> fallingSquares(vector<vector<int>>& positions) {
		int sz = positions.size();
		v.clear();
		memset(height, 0, sizeof height);
		for (auto x : positions) {
			int a = x[0];
			int b = x[0] + x[1] - 1;
			v.push_back(a), v.push_back(b);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		int maxHeight = 0;
		vector<int>	ans(sz);
		
		for (int i = 0; i < sz; i++) {
			int l = positions[i][0];
			int r = positions[i][0] + positions[i][1] - 1;
			l = query(l), r = query(r);
			int maxV = query(l, r);
			int h = positions[i][1];
			maxHeight = max(maxHeight, h + maxV);
			update(l, r, maxV + h);
			ans[i] = maxHeight;
		}

		return ans;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
	Solution s;
	vector<vector<int>> op = {{1, 2}, {2, 3}, {6, 1}};
	auto ans = s.fallingSquares(op);
	each(ans, it);
    return 0;
}

