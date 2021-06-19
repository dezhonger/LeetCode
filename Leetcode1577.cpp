typedef long long LL;


class Solution {
public:
    unordered_map<LL, int> findCnt(vector<int>& a) {
        unordered_map<LL, int> cnt;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) cnt[1LL * a[i] * a[j]]++;
        }
        return cnt;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        auto c1 = findCnt(nums1);
        auto c2 = findCnt(nums2);
        for (int i = 0; i < nums1.size(); i++) res += c2[1LL * nums1[i] * nums1[i]];
        for (int i = 0; i < nums2.size(); i++) res += c1[1LL * nums2[i] * nums2[i]];
        return res;
    }
};
