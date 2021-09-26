typedef long long LL;

class Solution {
public:
    LL s[2][50010];
    long long gridGame(vector<vector<int>>& g) {
        int n = g[0].size();
        for (int i = 1; i <= n; i++) {
            s[0][i] = s[0][i - 1] + g[0][i - 1];
            s[1][i] = s[1][i - 1] + g[1][i - 1];
        }
        LL ans = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            // 枚举第一个机器人拐弯的位置，第二个机器人只能选第一行的后缀以及第二行的前缀
            ans = min(ans, max(s[0][n] - s[0][i], s[1][i - 1]));

        }
        return ans;
    }
};
