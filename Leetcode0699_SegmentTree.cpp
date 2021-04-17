#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0699_SegmentTree.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-17 20:49:57

const int N = 2010;
struct Node {
	int l, r, v, c;
}tr[N << 2];

class Solution {
	public:
		vector<int>	xs;

		int get(int x) {
			return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
		}

		void pushup(int u) {
			tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
		}

		void pushdown(int u) {
			int c = tr[u].c;
			if (c > 0) {
				auto &l = tr[u << 1], &r = tr[u << 1 | 1];
				tr[u].c = 0;
				l.v = r.v = c;
				l.c = r.c = c;
			}
		}

		void build(int u, int l, int r) {
			tr[u] = {l, r};
			if (l == r) return ;
			int mid = l + r >> 1;
			build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		}

		void update(int u, int l, int r, int c) {
			if (tr[u].l >= l && tr[u].r <= r) {
				tr[u].c = tr[u].v = c;
				return ;
			}
			pushdown(u);
			int mid = tr[u].l + tr[u].r >> 1;
			if (l <= mid) update(u << 1, l, r, c);
			if (r > mid) update(u << 1 | 1, l, r, c);
			pushup(u);
		}

		int query(int u, int l, int r) {
			if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
			pushdown(u);
			int mid = tr[u].l + tr[u].r >> 1;
			int res = 0;
			if (l <= mid) res = max(res, query(u << 1, l, r));
			if (r > mid) res = max(res, query(u << 1 | 1, l, r));
			return res;
		}

		vector<int>	fallingSquares(vector<vector<int>>& pos) {
			for (auto& p : pos) {
				int a = p[0], b = a + p[1] - 1;
				xs.push_back(a), xs.push_back(b);
			}
			sort(xs.begin(), xs.end());
			xs.erase(unique(xs.begin(), xs.end()), xs.end());
			build(1, 0, xs.size() - 1);
			vector<int>	res;
			for (auto &p: pos) {
				int a = p[0], b = a + p[1] - 1;
				a = get(a), b = get(b);
				int h = query(1, a, b);
				update(1, a, b, h + p[1]);
				res.push_back(tr[1].v);
			}
			return res;
		}
};

int main() {
	ios::sync_with_stdio (false);
	cin.tie (0);
	return 0;
}

