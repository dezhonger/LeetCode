#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0564.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-17 21:26:21

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

class Solution {
public:
    string nearestPalindromic(string n) {
        set<LL> s;
		int sz = n.size();
		s.insert((LL)pow(10, sz) + 1);
		s.insert((LL)pow(10, sz - 1) - 1);
		string str = n.substr(0, (sz + 1) / 2);
		LL t = stoll(str);
		for (LL i = t - 1; i <= t + 1; i++) {
			string h = to_string(i);
			string j;
			if (sz % 2 == 1) j = h.substr(0, h.size() - 1);
			else j = h;
			reverse(j.begin(), j.end());
			string r = h + j;
			s.insert(stoll(r));
		}
		each(s, it);
		s.erase(stoll(n));
		string ans = "";
		LL d = LLONG_MAX; 
		for (LL st: s) {
			LL nd = abs(st - stoll(n));
			if (nd < d) {
				d = nd;
				ans = to_string(st);
			} else if (nd == d) {
				if (st < stoll(ans)) ans = to_string(st);
			}
		}
		return ans;
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
	Solution s;
	cout << s.nearestPalindromic("123") << endl;
	cout << s.nearestPalindromic("1234") << endl;
	cout << s.nearestPalindromic("1") << endl;
    return 0;
}

