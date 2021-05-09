#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1856.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-10 03:18:26
//Last modified: 2021-05-10 03:31:21

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
    vector<int> d1, d2;
    vector<LL> d3;
    void f1(vector<int>& a) {
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (s.size() && a[i] < a[s.top()]) {
                int c = s.top();
                s.pop();
                d1[c] = i - 1;
            }
            s.push(i);
        }
        while (s.size()) {
            int c = s.top();
            d1[c] = n - 1;
            s.pop();
        }
    }

    void f2(vector<int>& a) {
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() && a[i] < a[s.top()]) {
                int c = s.top();
                s.pop();
                d2[c] = i + 1;
            }
            s.push(i);
        }
        while (s.size()) {
            int c = s.top();
            d2[c] = 0;
            s.pop();
        }
    }


    int maxSumMinProduct(vector<int>& nums) {
        n = nums.size();
        d1 = vector<int>(n);
        d2 = vector<int>(n);
        d3 = vector<LL>(n + 1);
        f1(nums);f2(nums);
        d3[0] = 0;
        for (int i = 1; i <= n; i++) d3[i] = d3[i - 1] + nums[i - 1];
        LL res = 0;
        for (int i = 0; i < n; i++) {
            LL s = d3[d1[i] + 1] - d3[d2[i]];
            res = max(res, 1LL * nums[i] * s);
        }
        return res % mod;
    }
};



