#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0871.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-04 02:11:10
//Last modified: 2021-05-04 02:25:39

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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		int s = 0, ans = 0;
		priority_queue<pair<int, int>> q;
		stations.pb({target, 0});
		for (auto p : stations) {
			if (p[0] - s <= startFuel) {
				startFuel -= p[0] - s;
				q.push({p[1], p[0]});
				s = p[0];
			} else {
				while (q.size()) {
					auto c = q.top();
					q.pop();
					ans++;
					startFuel += c.F;
					if (startFuel >= p[0] - s) break;
				}
				if (startFuel >= p[0] - s) {
					q.push({p[1], p[0]});
				} else {
					return -1;
				}
			}
		}
		return ans;
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

