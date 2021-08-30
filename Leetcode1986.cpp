int f[1 << 15], dp[1 << 15];
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size(), mask = (1 << n) - 1;
        vector<int> v;
        for (int i = 0; i <= mask; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) s += tasks[j];
            }
            f[i] = s;
            if (s <= sessionTime) v.push_back(i);
        }
        dp[0] = 0;
        for (int i = 1; i <= mask; i++) {
            dp[i] = n + 1;
            for (int s: v) {
                //s是i的子集
                if ((i & s) == s) dp[i] = min(dp[i], dp[i ^ s] + 1);
            }
        }
        return dp[mask];
    }
};
