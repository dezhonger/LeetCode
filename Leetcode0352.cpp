typedef int LL;
#define F first
#define S second
class SummaryRanges {
public:
    set<pair<LL, LL>> s;
    /** Initialize your data structure here. */
    SummaryRanges() {
        s.insert({INT_MAX, INT_MAX});
        s.insert({INT_MIN, INT_MIN});
    }
    
    void addNum(int val) {
        //找到左端大于x的第一个区间
        auto j = s.upper_bound({val, INT_MAX});
        //左端点小于等于x最后一个区间
        auto i = j;
        i--;
        //区间已经包含了val
        if (i -> S >= val) return ;
        if (i -> S == val - 1 && j -> F == val + 1) {
            s.insert({i -> F, j -> S});
            s.erase(i);
            s.erase(j);
        } else if (i -> S == val - 1) {
            s.insert({i -> F, val});
            s.erase(i);
        } else if (j -> F == val + 1) {
            s.insert({val, j -> S});
            s.erase(j);
        } else {
            s.insert({val, val});
        }

    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& x: s) {
            if (x.F != INT_MIN && x.F != INT_MAX) {
                res.push_back({x.F, x.S});
            }
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
