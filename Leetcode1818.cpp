typedef long long LL;
int mod = (int)1e9 + 7;


class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        LL ans = 0;
        int n = nums2.size();
        for (int i = 0; i < n; i++) ans += abs(nums1[i] - nums2[i]);
        vector<int> v(nums1.begin(), nums1.end());
        sort(v.begin(), v.end());
        int d = 0;
        for (int i = 0; i < n; i++) {
            int now = abs(nums1[i] - nums2[i]);
            auto it = lower_bound(v.begin(), v.end(), nums2[i]);
            if (it != v.end()) {
                d = max(d, now - abs(*it - nums2[i]));
            }
            if (it != v.begin()) {
                auto pre = it;
                pre--;
                d = max(d, now - abs(*pre - nums2[i]));
            }
            
        }
        return (ans - d + mod) % mod;
    }
};
