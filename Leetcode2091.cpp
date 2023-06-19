class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int a = max_element(nums.begin(), nums.end()) - nums.begin();
        int b = min_element(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        return min({max(a ,b) + 1, n - min(a, b), min(a, b) + 1 + n - max(a, b)});

    }
};
