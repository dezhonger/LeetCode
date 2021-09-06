class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int s1 = 0, s2 = 0;
            for (int k = 0; k < i; k++) s1 += nums[k];
            for (int k = i + 1; k < n; k++) s2 += nums[k];
            if (s1 == s2) return i;
        }
        return -1;
    }
};
