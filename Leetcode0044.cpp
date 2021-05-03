#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0044.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-04 03:49:21
//Last modified: 2021-05-04 04:08:16

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

const int N = 2010;

class Solution {
public:
	bool f[N][N];
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i > 0) {
					if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) f[i][j] |= f[i - 1][j - 1];
				}
				if (p[j - 1] == '*') {
					f[i][j] |= f[i][j - 1];
					if (i > 0) f[i][j] |= f[i - 1][j];
				}
			}
		}
		return f[n][m];

    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
	Solution s;
	cout << s.isMatch("aa", "a") << endl;
    return 0;
}

