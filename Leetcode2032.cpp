class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> s;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        for (int x: nums3) {
            if (s1.count(x) || s2.count(x)) s.insert(x);
        }
        for (int x: s1) if (s2.count(x)) s.insert(x);
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};
