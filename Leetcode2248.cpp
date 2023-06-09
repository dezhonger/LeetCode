class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> v(1001);
        for (auto &x: nums) for (int y: x) v[y]++;
        vector<int> res;
        for (int i = 1; i <= 1000; i++) if (v[i] == nums.size()) res.push_back(i);
        return res;
    }
};
