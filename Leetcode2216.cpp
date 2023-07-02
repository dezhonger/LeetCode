class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] == nums[i + 1]) ans++; //可以视为删除nums[i]
            else i++;
        }
        if ((n - ans) % 2) ans++;
        return ans;
    }
};
