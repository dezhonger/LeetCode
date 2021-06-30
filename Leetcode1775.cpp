class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        if (l1 * 6 < l2 || l2 * 6 < l1) return -1;
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (s1 < s2) {
            swap(s1, s2);
            swap(nums1, nums2);
            swap(l1, l2);
        }
        // we have s1 > s2
        vector<int> c1(7), c2(7);
        for (int x : nums1) c1[x]++;
        for (int x : nums2) c2[x]++;
        int d = s1 - s2, res = 0;
        for (int i = 6; i > 1; i--) {
            int c = c1[i] + c2[7 - i];
            if (c * (i - 1) <= d) d -= c * (i - 1), res += c;
            else {
                int cn = (d + i - 2) / (i - 1);
                res += cn;
                break;
            }
        }
        return res;
    }
};
