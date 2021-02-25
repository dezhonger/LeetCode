class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
		unordered_map<int, int> mp;
        for (int a: nums) mp[a]++;
        sort(begin(nums), end(nums), [&](int a, int b) {
            return mp[a] == mp[b] ? a > b : mp[a] < mp[b];
        });
        return nums;
    }
};
