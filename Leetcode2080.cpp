class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> occ;
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) occ[arr[i]].emplace_back(i);
    }
    
    int query(int left, int right, int value) {
        auto& pos = occ[value];
        auto l = lower_bound(pos.begin(), pos.end(), left);
        auto r = upper_bound(pos.begin(), pos.end(), right);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
