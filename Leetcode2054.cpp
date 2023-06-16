class Solution {
public:
    struct Event
    {
        int ts, op, val;
        Event(int _ts, int _op, int _val): ts(_ts), op(_op), val(_val) {}
        bool operator< (const Event& that) const { return tie(ts, op) < tie(that.ts, that.op); }
    };

    int maxTwoEvents(vector<vector<int>>& events) {
        vector<Event> es;
        for (auto& e: events) es.push_back({e[0], 0, e[2]}), es.push_back({e[1], 1, e[2]});
        sort(es.begin(), es.end());

        int res = 0, best = 0;
        for (auto& [ts, op, val]: es)
        {
            if (op == 0) res = max(res, val + best);
            else best = max(best, val);
        }
        return res;
    }
};
