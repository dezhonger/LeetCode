#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1835.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-18 14:06:28

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
	
	void cal(vector<int>& arr, vector<int>& a) {
		for (int x : arr) {
			for (int i = 0; i < 32; i++) {
				if ((x >> i) & 1) a[i]++;
			}
		}
	}
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<int>	a(35), b(35);
		a.clear();
		b.clear();
		cal(arr1, a);
		cal(arr2, b);
		int ans = 0;
		for (int i = 0; i < 32; i++) {
			int c = (a[i] % 2) * (b[i] % 2);
			if (c & 1) ans |= (1 << i);
		}
		return ans;
    }
};


int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

