#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0864.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-04 01:28:12
//Last modified: 2021-05-04 02:00:22

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


struct Node {
	int x, y, k, j, s;
	bool operator< (const Node& w) const {
		if (x != w.x) return x < w.x;
		if (y != w.y) return y < w.y;
		return k < w.k;
	}
	friend ostream& operator<<(ostream& out, Node& w) {
		out << w.x << " " << w.y;
		return out;
	}
};

class Solution {
public:
	int n, m, z, x, y;
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

	int g(int x) {
		int res = 0;
		while (x) {
			if (x & 1) res++;
			x >>= 1;
		}
		return res;
	}

    int shortestPathAllKeys(vector<string>& grid) {
		n = grid.size(), m = grid[0].size(), z = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (grid[i][j] >= 'a' && grid[i][j] <= 'z') z++;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			if (grid[i][j] == '@') {
				x = i, y = j;
				break;
			}
		}
		Node node = {x, y, 0, 0, 0};
		queue<Node> q;
		q.push(node);
		set<Node> s;
		s.insert(node);
		while (q.size()) {
			auto c = q.front();
			q.pop();
			debug(c.x, c.y, c.k, c.j, c.s);
			if (c.j == z) return c.s;
			for (int i = 0; i < 4; i++) {
				int x = dx[i] + c.x, y = dy[i] + c.y;
				if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#') {
					int ck = c.k;
					if (grid[x][y] >= 'a' && grid[x][y] <= 'z') {
						ck = c.k | (1 << (grid[x][y] - 'a'));
					} else if (grid[x][y] >= 'A' && grid[x][y] <= 'Z') {
						if ((ck & (1 << (grid[x][y] - 'A'))) == 0) continue;
					}
					Node nxt = {x, y, ck, g(ck), c.s + 1};
					//已经遍历过了
					if (s.count(nxt)) continue;
					q.push(nxt);
					s.insert(nxt);
				}
			}

		}
		return -1;

    }
};

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio (false);
	cin.tie (0);
	Solution s;
	vector<string> v = {"@.a.#", "###.#", "b.A.B"};
	cout << s.shortestPathAllKeys(v) << endl;
	return 0;
}

