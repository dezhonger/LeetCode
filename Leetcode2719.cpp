class Solution {
public:
    const int MOD = 1e9+7;

    int f(string s, int mi, int ma)
    {
        int n = s.length();
        int dp[n][min(9 * n, ma) + 1];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, bool)> g = [&](int i, int sum, bool limit) -> int
        {
            if (sum > ma) return 0;
            if (i == n) return sum >= mi;
            if (!limit && dp[i][sum] != -1) return dp[i][sum];
            int res = 0;
            int up = limit ? s[i] - '0' : 9;
            for (int d = 0; d <= up; d++) res = (res + g(i + 1, sum + d, limit && d == up)) % MOD;
            if (!limit) dp[i][sum] = res;
            return res;
        };
        return g(0, 0, true);
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        int ans = f(num2, min_sum, max_sum) - f(num1, min_sum, max_sum) + MOD;
        int sum = 0;
        for (char c: num1) sum += c -  '0';
        ans += min_sum <= sum && sum <= max_sum;
        return ans % MOD;
    }
};
