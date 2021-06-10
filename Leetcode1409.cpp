const int N = 2005;

struct Bit {
    int n;
    vector<int> tr;

    Bit(int n) :n(n) { tr = vector<int>(n + 1, 0); }

    int lowbit(int x) { return x & (-x); }

    void add(int pos, int x) {
        for (int i = pos; i <= n; i += lowbit(i)) tr[i] += x;
    }

    int sum(int pos) {
        int res = 0;
        for (int i = pos; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
};

class Solution {
public:

    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res;
        vector<int> p(m + 1);
        int n = queries.size();
        Bit bit(n + m);
        for (int i = 1; i <= m; i++) p[i] = n + i;
        for (int i = 1; i <= m; i++) bit.add(n + i, 1);
        int nxtPos = n;
        for (int i = 0; i < n; i++) {
            int curPos = p[queries[i]];
            int s = bit.sum(curPos - 1);
            res.push_back(s);
            bit.add(p[queries[i]], -1);
            p[queries[i]] = nxtPos;
            bit.add(nxtPos, 1);
            nxtPos--;
        }
        return res;

    }
};
