class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int n = nums.size(), maxV = -1;
        for (int i = 0; i < (1 << n); i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) s |= nums[j];
            }
            cnt[s]++;
            maxV = max(maxV, s);
        }
        return cnt[maxV];
    }
};
