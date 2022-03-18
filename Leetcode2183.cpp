int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            ++freq[gcd(num, k)];
        }

        long long ans = 0;
        for (auto&& [x, occx]: freq) {
            for (auto&& [y, occy]: freq) {
                if (static_cast<long long>(x) * y % k == 0) {
                    ans += static_cast<long long>(occx) * occy;
                }
            }
        }

        for (int num: nums) {
            if (static_cast<long long>(num) * num % k == 0) {
                --ans;
            }
        }

        return ans / 2;
    }
};
