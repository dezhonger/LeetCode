typedef long long LL;
LL mod = 1000000007;

class Solution {
public:
    int minimumTime(string s) {
        int n = s.size(), pre = 0, ans = INT_MAX, best = INT_MAX;
        for (int j = 0; j < n; j++) {
            best = min(best, j - 2 * pre);
            pre += s[j] - '0';
            ans = min(ans, best + 2 * pre - j);
        }
        return min(ans + n - 1, n);
    }
};
