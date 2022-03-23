int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// __builtin_popcount

typedef long long LL;


class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for (int num: nums) {
            while (!ans.empty()) {
                int g = gcd(ans.back(), num);
                if (g > 1) {
                    num = ans.back() / g * num;
                    ans.pop_back();
                }
                else {
                    break;
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};

