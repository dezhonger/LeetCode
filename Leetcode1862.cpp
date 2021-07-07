typedef long long LL;
LL mod = (int)1e9 + 7;
const int N = 100010;
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<int> cnt(N), s(N);
        LL res = 0;
        int maxV = 0;
        for (int x: nums) cnt[x]++, maxV = max(maxV, x);
        for (int i = 1; i <= maxV; i++) s[i] = s[i - 1] + cnt[i];
        for (int y = 1; y <= maxV; y++) {
            if (!cnt[y]) continue;
            for (int d = 0; d <= maxV / y; d++) {
                // floor(x / y) = d 推出 d * y <= x < (d + 1) * y
                int r = (d + 1) * y - 1, l = d * y;
                int num = s[min(r, maxV)] - s[max(0, l - 1)];
                res += 1LL * num * d * cnt[y];
                res %= mod;
            }
        }
        return res;
    }
};
