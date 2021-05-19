#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0632.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-19 22:58:22
//Last modified: 2021-05-19 23:08:51

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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxV = INT_MIN;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i][0], i, 0});
            maxV = max(maxV, nums[i][0]);
        }

        vector<int> res;
        while (1) {
            auto c = pq.top();
            pq.pop();
            int l = c[0], r = maxV, i = c[1], j = c[2];
            if (res.empty() || r - l < res[1] - res[0]) res = {l, r};
            if (j + 1 < nums[i].size()) {
                pq.push({nums[i][j + 1], i, j + 1});
                maxV = max(maxV, nums[i][j + 1]);
            } else {
                break;
            }
        }
        return res;
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

