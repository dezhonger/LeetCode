typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

const int N = 100010;

struct Bit {
    int n;
    vector<LL> tr;

    Bit(int n) :n(n) { tr = vector<LL>(n + 1, 0); }

    void init() {
        fill(tr.begin(), tr.end(), 0);
    }
    int lowbit(int x) { return x & (-x); }

    void add(int pos, int x) {
        for (int i = pos; i <= n; i += lowbit(i)) tr[i] += x;
    }

    LL sum(int pos) {
        LL res = 0;
        for (int i = pos; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
}b1(N), b2(N);

class MKAverage {
    

public:
    int m, k;
    LL sum;
    queue<int> q;
    
    MKAverage(int m, int k) {
        this -> m = m;
        this -> k = k;
        this -> sum = 0;
        b1.init();
        b2.init();
    }
    
    void addElement(int num) {
        q.push(num);
        sum += num;
        //前缀次数和
        b1.add(num, 1);
        //前缀和
        b2.add(num, num);
        if (q.size() > m) {
            sum -= q.front();
            b1.add(q.front(), -1);
            b2.add(q.front(), -q.front());
            q.pop();
        }
    }
    
    //最小的k个数的和
    LL left() {
        int l = 1, r = N;
        while (l < r) {
            int mid = l + r >> 1;
            if (b1.sum(mid) < k) l = mid + 1;
            else r = mid;
        }
        return b2.sum(l) - (b1.sum(l) - k) * l;
    }
    
    //最大的k个数的和
    LL right() {
        int l = 1, r = N, c = m - k;
        while (l < r) {
            int mid = l + r >> 1;
            if (b1.sum(mid) < c) l = mid + 1;
            else r = mid;
        }
        return sum - (b2.sum(l) - l * (b1.sum(l) - c));
    }
    
    int calculateMKAverage() {
        if (q.size() < m) return -1;
        return (sum - left() - right()) / (m - k * 2);
        
    }
};
