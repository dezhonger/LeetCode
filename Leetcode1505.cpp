class BIT {
    vector<int> tr;
    int n;
    public:
    BIT(int _n): n(_n), tr(_n + 1) {}
    int lowbit(int x) {return x & (-x); }
    void add(int pos, int x) {
        for (int i = pos; i <= n; i += lowbit(i)) tr[i] += x;
    }
    int sum(int pos) {
        int res = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) res += tr[i];
        return res;
    }
    int query(int l, int r) {return sum(r) - sum(l - 1);}
};

class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();
        BIT bit(n);
        string ans;
        vector<queue<int>> v(10);
        for (int i = 0; i < n; i++) v[num[i] - '0'].push(i + 1);
        for (int i = 1; i <= n; i++) {
            //考虑第i为可以放置哪个数
            for (int j = 0; j < 10; j++) {
                if (v[j].empty()) continue;
                int pos = v[j].front();
                int dis = pos - i + bit.query(pos + 1, n);
                if (dis <= k) {
                    k -= dis;
                    ans += (j + '0');
                    bit.add(pos, 1);
                    v[j].pop();
                    break;
                }
            }
        }
        return ans;
    }
};
