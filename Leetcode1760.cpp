class Solution {
public:
    bool check(vector<int>& nums, int op, int v) {
        for (int x : nums) {
            op -= (x - 1) / v;
            if (op < 0) return 0;
        }
        return op >= 0;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int r = 0, l = 1;
        for (int x: nums) r = max(r, x);
        while (l < r) {
            int mid = l + r >> 1;
            if (check(nums, maxOperations, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
