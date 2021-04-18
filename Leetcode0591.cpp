#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0591.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-18 14:51:15

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
    bool isValid(string code) {
        stack<string> stk;
		int n = code.size();
		for (int i = 0; i < n; i++) {
			if (code[i] == '<' && code.substr(i, 9) != "<![CDATA[") {
				//是标签名
				int j = i + 1;
				string tagName;
				bool end = false;
				while (j < n && code[j] != '>') {
					char c = code[j++];
					if (c == '/' && j == i + 2) {
						end = true; //结束标签
						continue;
					}
					if (c < 'A' || c >= 'Z') return false; //不是标签的合法字符
					tagName += c;
				}
				if (j == n) return false; //标签没有以'>'结束
				if (tagName.size() < 1 || tagName.size() > 9) return false;

				if (end) {
					if (stk.empty() || stk.top() != tagName) return false; //标签必须有匹配
					stk.pop();
				} else {
					if (i > 0 && stk.empty()) return false; //最外层只能有一个标签
					stk.push(tagName);
				}
				i = j;
			} else {
				//process tag content
				if (stk.empty()) return false;
				if (code.substr(i, 9) == "<![CDATA[") {
					int j = i;
					while (j < n && code.substr(j, 3) != "]]>") j++;
					if (j == n) return false;
					i = j + 2;
				}
			}
		}
		return stk.empty();
    }
};

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    return 0;
}

