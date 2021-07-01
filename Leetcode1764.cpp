class Solution {
public:
    bool check(vector<int>& nums, int k, vector<int>& g) {
        for (int i = 0; i < g.size(); i++) {
            if (k + i >= nums.size() || g[i] != nums[k + i]) return 0;
        }
        return 1;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size(), k = 0, m = groups.size(), i = 0;
        for (i = 0; i < m && k < n;) {
            if (check(nums, k, groups[i])) {
                k += groups[i].size();
                i++;
            } else {
                k++;
            }
        }
        return i == m;
    }
};
