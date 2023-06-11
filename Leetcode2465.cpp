class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<double> st;
        sort(nums.begin(), nums.end());
        int s = 0, sz = nums.size(), start = 0, end = nums.size() - 1;
        for (int x: nums) s += x;
        while (sz)
        {
            st.insert(1.0 * (nums[start] + nums[end]) / 2);
            s = s - nums[start++] - nums[end--];
            sz -= 2;
        }

        return st.size();
    }
};
