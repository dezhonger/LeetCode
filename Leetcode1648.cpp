#define F first
#define S second

typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

// int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}


class Solution {
public:
    vector<PII> getMax(map<int, int> &mp) {
        vector<PII> res;
        auto it = mp.rbegin();
        res.push_back({it -> F, it -> S});
        it++;
        if (it != mp.rend()) res.push_back({it -> F, it -> S});
        else res.push_back({0, 0});
        return res;
    }

    int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size();
        priority_queue<PII> pq;
        //<个数, 数量>
        map<int, int> cnt;
        for (int x: inventory) cnt[x]++;
        // for (auto [k, v]: cnt) pq.push({k, v});
        LL res = 0;
        while (orders > 0) {
            vector<PII> v = getMax(cnt);
            LL d = 1LL * (v[0].F - v[1].F) * v[0].S;
            if (d > orders) {
                int complete = orders / v[0].S;
                LL gain = 1LL * v[0].S * (v[0].F + v[0].F - complete + 1) * complete / 2;
                int every = v[0].F - complete;
                gain += 1LL * every * (orders % v[0].S);
                res += gain;
                orders = 0;
            } else {
                orders -= d;
                cnt.erase(v[0].F);
                cnt[v[1].F] += v[0].S;
                
                // 全部需要计算上
                //计算贡献 S * (F + 1, F + 2 + ... )
                LL gain = 1LL * v[0].S * (v[1].F + 1 + v[0].F) * (v[0].F - v[1].F) / 2;
                res += gain;
            }

            res %= mod;
        }
        return res;
    }
};
