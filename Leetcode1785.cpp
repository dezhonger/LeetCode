class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long s = accumulate(nums.begin(), nums.end(), -goal * 1LL);
        return (abs(s) + limit - 1) / limit;
    }
};
