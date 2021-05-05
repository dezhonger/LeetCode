#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0335.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-05 22:32:56
//Last modified: 2021-05-05 22:54:33

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
        bool isSelfCrossing(vector<int>& d) {
            int n = d.size();
            for (int i = 3; i < n; i++) {
                if (i >= 3) {
                    if (d[i - 1] <= d[i - 3] && d[i] >= d[i - 2]) return true;
                }
                if (i >= 4) {
                    if (d[i - 3] == d[i - 1] && d[i] + d[i - 4] >= d[i - 2]) return true;
                    if (d[i - 3] > d[i - 1] && d[i] > d[i - 2]) return true;
                }
                if (i >= 5) {
                    if (d[i - 2] > d[i - 4] && d[i - 1] <= d[i - 3]  && d[i - 1] >= d[i - 3] - d[i - 5] && d[i] >= d[i - 2] - d[i - 4]) return true;
                }
            }
            return false;
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

