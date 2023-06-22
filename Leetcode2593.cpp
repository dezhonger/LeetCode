class Solution {
public:
    long long findScore(vector<int> &nums) {
        int n = nums.size(), ids[n];
        iota(ids, ids + n, 0);
        stable_sort(ids, ids + n, [&](int i, int j) {
            return nums[i] < nums[j];
        });

        long long ans = 0;
        bool vis[n + 2]; // 保证下标不越界
        memset(vis, 0, sizeof(vis));
        for (int i : ids)
            if (!vis[i + 1]) { // 避免 -1，偏移一位
                vis[i] = vis[i + 2] = true;
                ans += nums[i];
            }
        return ans;
    }
};
