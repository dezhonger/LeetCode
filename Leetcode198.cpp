class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int l = nums.size();
        int tou = nums[0], butou = 0;
        int ans1, ans2;
        for(int i = 1; i < l; i++) {
            ans1 = nums[i] + butou;
            ans2 = max(tou, butou);
            tou = ans1;
            butou = ans2;
        }
        return max(tou, butou);
    }
};
