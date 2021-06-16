typedef long long LL;
LL mod = (int)1e9 + 7;

class Solution {
public:
    LL rev(int x) {
        string s = to_string(x);
        reverse(s.begin(), s.end());
        return stoll(s);
    }

    int countNicePairs(vector<int>& nums) {
        LL res = 0;
        for (int& x : nums) x -= rev(x);
        unordered_map<int, int> c;
        for (int x : nums) c[x]++;
        for (auto [k, v]: c) {
            res += 1LL * (v - 1) * v / 2;
            res %= mod;
        }
        return res;
    }
};
