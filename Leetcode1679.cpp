class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> cnt;
        int res = 0;
        for (int x: nums) cnt[x]++;
        for (auto [a, b]: cnt) {
            int f = k - a, g;
            if (f != a) {
                g = min(b, cnt[f]);
            } else {
                g = b / 2;
            }
            
            cnt[a] -= g;
            cnt[f] -= g;
            res += g;
        }
        return res;
    }
};
