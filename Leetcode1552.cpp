#include <bits/stdc++.h>
using namespace std;
//Filename: 1552.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2020-08-17 19:35:01

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
	int check(int mid, vector<int> p,int m) {
		int sz = p.size();
		int last = -1;
		int k = 0;
		for (int i = 0; i < sz; i++) {
			if (last == -1 || p[i] - last >= mid) {
				last = p[i];
				k++;
				if (k == m) return 1;
			}	
		}
		return 0;
	}
    int maxDistance(vector<int>& position, int m) {
		sort(position.begin(), position.end());
		int sz = position.size();
		int l = 1, r = position[sz - 1];
	    while (l < r) {
			int mid = (1 + l + r) / 2;
			if (check(mid, position, m)) l = mid;
			else r = mid - 1;
		}	
		return l;
    }
};
int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}
