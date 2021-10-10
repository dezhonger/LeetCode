class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<vector<int>> mp1(n + 1), mp2(n + 1);
        for (int i = 0; i < (1 << n); i++) {
            int k = __builtin_popcount(i);
            int s = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) s += nums[j];
            }
            mp1[k].push_back(s);
        }
        
        for (int i = 0; i < (1 << n); i++) {
            int k = __builtin_popcount(i);
            int s = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) s += nums[j + n];
            }
            mp2[k].push_back(s);
        }
        for (int i = 0; i <= n; i++) {
            sort(mp1[i].begin(), mp1[i].end());
            sort(mp2[i].begin(), mp2[i].end());
        }
        int s = 0;
        for (int x: nums) s += x;
        int ans = abs(s - (mp2[n].back()) * 2);
        for (int i = 1; i <= (n + 1) / 2; i++) {
            auto candidate1 = mp1[i];
            auto candidate2 = mp2[n - i];
            int rb = *candidate2.rbegin();
            for (auto x: candidate1) {
                int t = (s - 2 * x) / 2;
                auto it = lower_bound(candidate2.begin(), candidate2.end(), t);
                if (it != candidate2.end()) {
                    ans = min(ans, abs(s - (x + *it) * 2));
                    if (it != candidate2.begin()) {
                        it--;
                        ans = min(ans, abs(s - (x + *it) * 2));
                    }
                } else {
                    ans = min(ans, abs(s - (x + rb) * 2));
                }
            }
        }
        return ans;
    }
};
