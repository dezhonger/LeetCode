void upmin(int& x, int y) {
    if (y < x) x = y;
}

int dp[17][(1 << 17) - 1];
class Solution {
public:
    int cal(int mask, vector<int>& a) {
        int res = 0;
        int maxV = INT_MIN, minV = INT_MAX;
        unordered_set<int> s;
        for (int i = 0; i < a.size(); i++) {
            if ((mask >> i) & 1) {
                int v = a[i];
                if (s.count(v)) return -1;
                maxV = max(maxV, v);
                minV = min(minV, v);
                s.insert(v);
            }
        }
        return maxV - minV;
    }
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size(), m = n / k;
        //k: 组数 m:每组的元素个数
        unordered_map<int, int> ump;
        unordered_map<int, int> mask;
        unordered_map<int, vector<int>> mv;
        for (int x: nums) {
            ump[x]++;
            if (ump[x] > k) return -1;
        }
        for (int i = 0; i < (1 << n); i++) {
            int o = __builtin_popcount(i);
            if (o % m == 0) mv[o / m].push_back(i);
        }


        for (int h: mv[1]) {
            int d = cal(h, nums);
            if (d != -1) mask[h] = d;
        }
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        for (int i = 1; i <= k; i++) {
            // dp[i][j]:前i组mask为j的答案的最小值
            for (int j: mv[i]) {
                for (auto& [h1, h2]: mask) {
                    upmin(dp[i][j], dp[i - 1][j ^ h1] + h2);
                }
            }
        }
        return dp[k][(1 << n) - 1];
    }
};
