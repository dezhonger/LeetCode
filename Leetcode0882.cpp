#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0882.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-03 23:18:30
//Last modified: 2021-05-04 01:12:52

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

typedef pair<int, int> PII;

const int N = 3010, M = 20010;

class Solution {
	public:
		int h[N], e[M], ne[M], w[M], idx;
		int dis[N], st[N];
		vector<int> vn, vm;
		vector<vector<int>> ed;

		void add(int a, int b, int c) {
			e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
		}

		void dijkstra() {
			memset(dis, 0x3f, sizeof dis);
			priority_queue<PII, vector<PII>, greater<PII>> q;;
			q.ps({0, 0});
			dis[0] = 0;
			while (q.size()) {
				auto cur = q.top();
				q.pop();
				int node = cur.S;
				int distance = cur.F;
				if (st[node]) continue;
				st[node] = 1;
				for (int i = h[node]; ~i; i = ne[i]) {
					int u = e[i];
					if (dis[u] > distance + w[i]) {
						dis[u] = distance + w[i];
						q.ps({dis[u], u});
					}
				}
			}
		}


		int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
			idx = 0;
			memset(h, -1, sizeof h);
			memset(st, 0, sizeof st);
			for (auto& x : edges) {
				add(x[0], x[1], x[2] + 1), add(x[1], x[0], x[2] + 1);
			}
			dijkstra();
			int res = 0;
			for (int i = 0; i < n; i++) {
				if (dis[i] <= maxMoves) res++;
			}
			debug(res);
			for (int i = 0; i < n; i++) debug(i, dis[i]);
			for (int i = 0; i < idx; i += 2) {
				int a = e[i], b = e[i ^ 1];
				if (dis[a] <= maxMoves && dis[b] <= maxMoves) res += min(w[i] - 1, maxMoves - dis[a] + maxMoves - dis[b]);
				else if (dis[a] <= maxMoves) res += min(w[i] - 1, maxMoves - dis[a]);
				else if (dis[b] <= maxMoves) res += min(w[i] - 1, maxMoves - dis[b]);
				debug(a, b, w[i], res);
			}
			return res;
		}
};

int main() {
	ios::sync_with_stdio (false);
	cin.tie (0);
	Solution s;
	vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 1}, {1, 2, 2}};
	vector<vector<int>> edges2 = {{0,2,9},{0,1,6},{3,4,7},{2,3,8},{1,2,0},{2,4,0},{0,4,9},{0,3,0},{1,4,2},{1,3,0}};
	cout << s.reachableNodes(edges2, 3, 5) << endl;
	return 0;
}

