const int N = 100010;
struct node {
    int l, r, v;
}tr[N << 2];


void pushUp(int cur) {
	tr[cur].v = min(tr[cur << 1].v, tr[cur << 1 | 1].v);
}

void build(int cur, int l, int r) {
	tr[cur] = {l, r};
	if (l == r) return;
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
}

void modify(int cur, int pos, int val) {
	if (tr[cur].l == tr[cur].r) tr[cur].v = val;
	else {
		int mid = tr[cur].l + tr[cur].r >> 1;
		if (pos <= mid) modify(cur << 1, pos, val);
		else modify(cur << 1 | 1, pos, val);
		pushUp(cur);
	}
}

int query(int cur, int l, int r) {
	if (tr[cur].l >= l && tr[cur].r <= r) return tr[cur].v;
	int mid = tr[cur].l + tr[cur].r >> 1;
	int res = 1e8;
	if (l <= mid) res = min(res, query(cur << 1, l, r));
	if (r > mid) res = min(res, query(cur << 1 | 1, l, r));
	return res;
}

class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<vector<int>> v1(10);
        int n = s.size();
        build(1, 1, n);
        for (int i = 1; i <= n; i++) modify(1, i, s[i - 1] - '0');
        for (int i = 0; i < n; i++) v1[s[i] - '0'].push_back(i);
        for (int i = 0; i < 10; i++) reverse(v1[i].begin(), v1[i].end());
        for (int i = 0; i < n; i++) {
            int c = t[i] - '0';
            if (v1[c].empty()) return false;
            int idx = v1[c].back();
            int val = query(1, 1, idx);
            // debug(i, c, idx, val);
            if (val < c) return false;
            v1[c].pop_back();
            modify(1, idx + 1, 1e8);
            
        }
        return true;
    }
};
