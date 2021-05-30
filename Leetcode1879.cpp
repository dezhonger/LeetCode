#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1879.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-30 22:40:27
//Last modified: 2021-05-30 22:49:48

#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define reps(i, a, b) for(int i = (a); i <= (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second
#define each(x,y) for(auto y = x.begin(); y != x.end(); y++) cout << *y << " "; cout << endl;
#define Debug(x) cout<<#x<<"="<<x<<endl;

const int mod = int (1e9) + 7;
const double EPS = 1e-6;

typedef long long LL;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}

class Solution {
public:
    int f[15][(1 << 14) - 1];
    int get(int x) {
        int res = 0;
        while(x) {
            res += x % 2;
            x >>= 1;
        }
        return res;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = (1 << n);
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                int cone = get(j);
                if (cone != i) continue;
                f[i][j] = INT_MAX;
                for (int k = 0; k < n; k++) {
                    //j的第k位是1
                    if ((j >> k) & 1) f[i][j] = min(f[i][j], f[i - 1][j ^ (1 << k)] + (nums1[i - 1] ^ nums2[k]));
                }
            }
        }
        return f[n][m - 1];
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
