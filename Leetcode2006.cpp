class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> c;
        int d = 0;
        for (int x: nums) c[x]++;
        for (int x: nums) d += c[x + k] + c[x - k];
        return d / 2;
    }
};
