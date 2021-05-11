class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int h1 = INT_MAX, c1, h2 = INT_MAX, c2;
        int n = nums.size();
        for (int x: nums) {
            if (x == h1) c1++;
            else if (x == h2) c2++;
            else {
                if (h1 == INT_MAX) h1 = x, c1 = 1;
                else if (h2 == INT_MAX) h2 = x, c2 = 1;
                else {
                    c1--, c2--;
                    if (c1 == 0) h1 = INT_MAX;
                    if (c2 == 0) h2 = INT_MAX;
                }
            }


        }
        vector<int> res;
        int z1 = 0, z2 = 0;
        for (int x : nums) {
            if (x == h1) z1++;
            else if (x == h2) z2++;
        }
        if (z1 > n / 3) res.push_back(h1);
        if (z2 > n / 3) res.push_back(h2);
        return res;
    }
};
