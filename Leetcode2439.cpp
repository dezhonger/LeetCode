class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = *max_element(nums.begin(), nums.end()), n = nums.size();

        auto check = [&](int x) -> bool
        {
            vector<long long> a(n);
            for (int i = 0; i < n; i++) a[i] = (long long)nums[i];
            for (int i = n - 1; i > 0; i--)
            {
                if (a[i] > x) a[i - 1] += a[i] - x;
            }
            return a[0] <= x;
        };

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
