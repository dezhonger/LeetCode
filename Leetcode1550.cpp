#include <bits/stdc++.h>
using namespace std;
//Filename: 1550.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2020-08-17 12:40:51

#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define reps(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back
#define ps push
#define mp make_pair
#define CLR(x,t) memset(x,t,sizeof x)
#define LEN(X) strlen(X)
#define F first
#define S second

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
    bool threeConsecutiveOdds(vector<int>& arr) {
		int sz = arr.size();
	    for (int i = 2; i < sz; i++) {
			if (arr[i] % 2 == 1 && arr[i-1] % 2 == 1 && arr[i-2] % 2 == 1) {
				return true;	
			}	
		}	
		return false;

    }
};
int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}
