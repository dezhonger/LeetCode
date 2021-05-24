class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        typedef pair<int, int> PII;
        int n = intervals.size();
        vector<PII> v;
        for (auto& x: intervals) v.push_back({x[0], x[1]});
        sort(v.begin(), v.end());
        int s = v[0].first, e = v[0].second;
        vector<vector<int>> res;
        for (int i = 1; i < n; i++) {
            if (v[i].first > e) {
                //开启一个新区间
                res.push_back({s, e});
                s = v[i].first;
                e = v[i].second;
            } else {
                e = max(e, v[i].second);
            }
        }
        //记得加入最后一个区间
        res.push_back({s, e});
        return res;
    }
};
