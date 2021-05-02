#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode1851.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-02 22:40:46
//Last modified: 2021-05-02 23:26:48

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

LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}

class Solution {
public:
	vector<int> u, ans, ans2;
	int bucket, sz;
	int getBucket(int x) {
		return x / bucket;
	}
	int get(int x) {
		return lower_bound(u.begin(), u.end(), x) - u.begin();
	}


	void update(int l, int r, int c) {
		int ll = getBucket(l), rr = getBucket(r);
		if (ll == rr) {
			for (int i = l; i <= r; i++) ans[i] = min(ans[i], c);
		} else {
			for (int i = ll + 1; i <= rr - 1; i++) ans2[i] = min(ans2[i], c);
			int rll = (ll + 1) * bucket - 1;
			for (int i = l; i <= rll; i++) ans[i] = min(ans[i], c);
			int lrr = rr * bucket;
			for (int i = lrr; i <= r; i++) ans[i] = min(ans[i], c);
		}
	}
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		u.clear();
		for (auto x : intervals) {
			u.pb(x[0]), u.pb(x[1]);
		}
		u.pb(0);
		u.pb(1e8);
		sort(u.begin(), u.end());
		vector<int> add;
		for (int i = 1; i < u.size(); i++) {
			if (u[i] - u[i - 1] > 1) add.pb(u[i] - 1);
		}
		for (int x : add) u.pb(x);
		sort(u.begin(), u.end());
		u.erase(unique(u.begin(), u.end()), u.end());
		int l = 0, r = u.size() - 1;
	   	sz = r - l + 1;
		ans.resize(sz, INT_MAX);
		bucket = (int)sqrt(sz);
		ans2.resize(sz, INT_MAX);
		for (auto x : intervals) {
			int a = x[0], b = x[1], c = b - a + 1;
			a = get(a), b = get(b);
			update(a, b, c);
		}
		vector<int>	res(queries.size());

		for (int i = 0; i < queries.size(); i++) {
			int x = queries[i];
			x = get(x);
			res[i] = (min(ans[x], ans2[getBucket(x)]));
			if (res[i] == INT_MAX) res[i] = -1;
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
	Solution s;
	vector<vector<int>> in = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
	vector<int> q = {2, 3, 4, 5, 100};

	auto res = s.minInterval(in, q);
	debug(res);
    return 0;
}

