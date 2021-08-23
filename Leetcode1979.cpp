int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }


class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*max_element(nums.begin(), nums.end()), *min_element(nums.begin(), nums.end()));
    }
};
