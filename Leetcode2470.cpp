class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        // https://leetcode.cn/problems/number-of-subarrays-with-lcm-equal-to-k/solution/by-endlesscheng-3qnt/
        int ans = 0, start = -1, n = nums.size();
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            if (k % x != 0)
            {
                a.clear();
                start = i;
                continue;
            }

            a.push_back(make_pair(x, i));
            // 原地去重，并求出以x为数组右端点的lcm数组
            int j = 0;
            for (auto& p: a)
            {
                p.first = lcm(p.first, x);
                if (a[j].first != p.first) j++, a[j] = p;
                else a[j].second = p.second;
            }

            a.resize(j + 1);
            if (a[0].first == k) ans += a[0].second - start;
        }
        return ans;
    }
};
