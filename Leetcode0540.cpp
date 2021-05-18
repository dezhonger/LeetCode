#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0540.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-18 22:14:53
//Last modified: 2021-05-18 22:16:05

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
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(nums[n - 1] + 1);
        //每两个数一组
        int l = 0, r = n / 2;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid * 2] == nums[mid * 2 + 1]) l = mid + 1;
            else r = mid;
        }
        return nums[l * 2];
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

