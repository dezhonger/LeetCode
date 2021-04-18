#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0903.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-19 00:43:34

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

const int N = 200 + 5;
int f[N][N];

//https://www.cnblogs.com/grandyang/p/11094525.html 第一种解法

//DID: 1032

//要变为DIDI: 2种情况，末尾+4 -> 10324
//                     末尾+3 -> 10423(大于3的数先加1，然后末尾加上3)
//要变为DIDD: 3种情况，末尾+2 -> 10432(大于2的数先加1，然后末尾加上2)
//                     末尾+1 -> 20431(大于1的数先加1，然后末尾加上1)
//                     末尾+0 -> 21430(大于0的数先加1，然后末尾加上0)


//f[i][j]:前i位(使用的数字为0到i)且末尾为j的符合答案的个数
class Solution {
public:
	void add(int& a, int b) {
		a += b;
		a %= mod;
	}

    int numPermsDISequence(string S) {
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		int n = S.size();
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				if (S[i - 1] == 'D') {
					for (int k = j; k < i; k++) add(f[i][j], f[i - 1][k]);
				} else {
					for (int k = 0; k < j; k++) add(f[i][j], f[i - 1][k]);
				}
			}
		}
		int ans = 0;
		for (int k = 0; k <= n; k++) add(ans, f[n][k]);
		return ans;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

