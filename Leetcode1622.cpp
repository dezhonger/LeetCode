int mod = (int)1e9 + 7;
int p = (int)1e9 + 7;

typedef long long LL;

const int N = 100010;
struct Node {
    int l, r;
    int sum, add, mul;
}tr[N * 4];

void pushup(int u) 
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void eval(Node &t, int add, int mul)
{
    t.sum = ((LL)t.sum * mul + (LL)(t.r - t.l + 1) * add) % p;
    t.mul = (LL)t.mul * mul % p;
    t.add = ((LL)t.add * mul + add) % p;
}

void pushdown(int u)
{
    eval(tr[u << 1], tr[u].add, tr[u].mul);
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1;
}


void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, 0, 0, 1};
    else
    {
        tr[u] = {l, r, 0, 0, 1};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int add, int mul)
{
    if (tr[u].l >= l && tr[u].r <= r) eval(tr[u], add, mul);
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, add, mul);
        if (r > mid) modify(u << 1 | 1, l, r, add, mul);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if (l <= mid) sum = query(u << 1, l, r);
    if (r > mid) sum = (sum + query(u << 1 | 1, l, r)) % p;
    return sum;
}

class Fancy {
public:
    int idx;
    Fancy() {
        idx = 0;
        build(1, 1, 100000);
    }
    
    void append(int val) {
        ++idx;
        modify(1, idx, idx, val, 1);
    }
    
    void addAll(int inc) {
        if (idx) modify(1, 1, idx, inc, 1);
    }
    
    void multAll(int m) {
        if (idx) modify(1, 1, idx, 0, m);
    }
    
    int getIndex(int idx) {
        if (idx >= this -> idx) return -1;
        return query(1, idx + 1, idx + 1);
    }
};
