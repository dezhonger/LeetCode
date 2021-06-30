#define M 1010

class Solution {
private:
    int f[M][M];

public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        const int n = nums.size(), m = multipliers.size();
        f[0][0] = 0;

        for (int i = 1; i <= m; i++)
            for (int j = 0; j <= i; j++) {
                f[i][j] = INT_MIN;
                int p = multipliers[i - 1];
                if (j >= 1)
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + p * nums[j - 1]);
                if (i - j >= 1)
                    f[i][j] = max(f[i][j], f[i - 1][j] + p * nums[n - (i - j)]);
            }

        int ans = INT_MIN;
        for (int i = 0; i <= m; i++)
            ans = max(ans, f[m][i]);

        return ans;
    }
};

