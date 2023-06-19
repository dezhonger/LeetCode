class Solution {
public:
    int minimizeMax(vector<int> &nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];
        while (left  < right) { // 开区间
            int mid = left + (right - left) / 2, cnt = 0;
            for (int i = 0; i < nums.size() - 1; ++i)
                if (nums[i + 1] - nums[i] <= mid) {
                    ++cnt;
                    ++i;
                }
            if (cnt >= p) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
