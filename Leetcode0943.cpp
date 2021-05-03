#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0943.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-04 02:53:44
//Last modified: 2021-05-04 03:23:17

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

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
void my_assert(bool x) {
  if (!x) {
    cout << "NO" << '\n';
    exit(0);
  }
}


typedef long long LL;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}

class Solution {
	public:
		//max overleaf length
		int calc(string &x, string &y) {
			int n = x.size(), m = y.size();
			int ma = min(m, n);
			while (ma) {
				bool f = true;
				for (int i = n - ma, j = 0; j < ma; i++, j++) {
					if (x[i] != y[j]) {
						f = false;
						break;
					}
				}
				if (f) return ma;
				ma--;
			}
			return ma;
		}

		string shortestSuperstring(vector<string>& words) {
			int n = words.size();
			//f[i][j]: i为位运算表示的集合。 考虑集合是i的字符串中，以第j个结尾的最短长度
			vector<vector<int>> f(1 << n, vector<int>(n, 1000));
			vector<vector<int>> p(1 << n, vector<int>(n, -1));
			vector<vector<int>> t(1 << n, vector<int>(n, 0));

			for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) t[i][j] = calc(words[i], words[j]);

			//init
			for (int i = 0; i < n; i++) f[1 << i][i] = words[i].size();
			
			for (int S = 0; S < (1 << n); S++) {
				for (int i = 0; i < n; i++) {
					if (S & (1 << i)) {
						for (int j = 0; j < n; j++) {
							if (!(S & (1 << j))) {
								if (f[S | 1 << j][j] > f[S][i] + words[j].size() - t[i][j]) {
									f[S | 1 << j][j] = f[S][i] + words[j].size() - t[i][j];
									//记录转移状态
									p[S | 1 << j][j] = i;
								}
							}
						}
					}
				}
			}

			int ans = 1000, k = -1;
			for (int i = 0; i < n; i++) {
				if (ans > f[(1 << n) - 1][i]) {
					ans = f[(1 << n) - 1][i];
					k = i;
				}
			}

			//先把答案初始为ans个空格的字符串，然后赋值
			string res = string(ans, ' ');
			int S = (1 << n) - 1, pos = ans;
			while (1) {
				for (int i = pos - words[k].size(), j = 0; i < pos && j < words[k].size(); i++, j++) {
					res[i] = words[k][j];
				}
				if (p[S][k] == -1) break;
				int kk = p[S][k];
				pos = pos - words[k].size() + t[kk][k];
				S ^= (1 << k);
				k = kk;
			}
			return res;

		}
};

int main() {
	Solution s;
	vector<string> v = {"alex","loves","leetcode"};
	cout << s.shortestSuperstring(v) << endl;
	return 0;
}

