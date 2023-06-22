class Solution {
public:
    int findSmallestInteger(vector<int> &nums, int m) {
        unordered_map<int, int> cnt;
        for (int x : nums) ++cnt[(x % m + m) % m];
        int mex = 0;
        while (cnt[mex % m]-- > 0) mex++;
        return mex;
    }
};
