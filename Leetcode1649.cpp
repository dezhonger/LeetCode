
typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

// int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}


const int n = 100010;
struct Node {
	int l, r, v;
}tr[n << 2];

void pushUp(int cur) {
	tr[cur].v = tr[cur << 1].v + tr[cur << 1 | 1].v;
}

void build(int cur, int l, int r) {
	tr[cur] = {l, r, 0};
	if (l == r) return;
	int mid = l + r >> 1;
	build(cur << 1, l, mid);
	build(cur << 1 | 1, mid + 1, r);
}

void modify(int cur, int pos, int val) {
	if (tr[cur].l == tr[cur].r) tr[cur].v += val;
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
	int res = 0;
	if (l <= mid) res += query(cur << 1, l, r);
	if (r > mid) res += query(cur << 1 | 1, l, r);
	return res;
}


class Solution {
public:

    int createSortedArray(vector<int>& instructions) {
        LL res = 0;
        int sz = instructions.size(), m = 100000;
        build(1, 1, m);
        for (int i = 0; i < instructions.size(); i++) {
            int x = instructions[i];
            int l = query(1, 1, x - 1), r = query(1, 1, x);
            res += min(l, i - r);
            res %= mod;
            modify(1, x, 1);
        }
        return res;
    }
};
