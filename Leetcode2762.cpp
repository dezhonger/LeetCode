class Solution {
public:
    long long continuousSubarrays(vector<int> &nums) {
        long long ans = 0;
        multiset<int> s;
        int left = 0, n = nums.size();
        for (int right = 0; right < n; right++) {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > 2) s.erase(s.find(nums[left++]));
            ans += right - left + 1;
        }
        return ans;
    }
};
