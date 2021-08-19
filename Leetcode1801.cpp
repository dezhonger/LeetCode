
typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

struct Sell {
    int cnt, price;
    bool operator<(const Sell& w) const {
        return w.price < price;
    }
};

struct Buy {
    int cnt, price;
    bool operator<(const Buy& w) const {
        return price < w.price;
    }
};

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<Sell> sell;
        priority_queue<Buy> buy;
        int n = orders.size();
        for (auto& o: orders) {
            int c = o[1], p = o[0];
            if (o[2] == 0) {
                //采购订单
                if (sell.empty() || sell.top().price > p) {
                    //没有匹配的
                    buy.push({o[1], o[0]});
                } else {
                    while(c && sell.size() && sell.top().price <= p) {
                        auto cur = sell.top();
                        sell.pop();
                        int mvCnt = min(cur.cnt, c);
                        c -= mvCnt;
                        cur.cnt -= mvCnt;
                        if (cur.cnt) sell.push(cur);
                    }
                    if (c) buy.push({c, o[0]});
                }
            } else {
                //销售订单
                if (buy.empty() || buy.top().price < p) {
                    //没有匹配的
                    sell.push({o[1], o[0]});
                } else {
                    while(c && buy.size() && buy.top().price >= p) {
                        auto cur = buy.top();
                        buy.pop();
                        int mvCnt = min(cur.cnt, c);
                        c -= mvCnt;
                        cur.cnt -= mvCnt;
                        if (cur.cnt) buy.push(cur);
                    }
                    if (c) sell.push({c, o[0]});
                }
            }
        }
        LL ans = 0;
        while (buy.size()) ans += buy.top().cnt, buy.pop();
        while (sell.size()) ans += sell.top().cnt, sell.pop();
        return ans % mod;
    }
};
