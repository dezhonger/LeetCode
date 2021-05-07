class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size();
        vector<vector<int>> res;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            if (i && a[i] == a[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && a[j] == a[j - 1]) continue;
                for (int k = j + 1, u = n - 1; k < u; k++) {
                    if (k > j + 1 && a[k] == a[k - 1]) continue;
                    while (u - 1 > k && a[i] + a[j] + a[k] + a[u - 1] >= target) u--;
                    if (a[i] + a[j] + a[k] + a[u] == target) res.push_back({a[i], a[j], a[k], a[u]});
                }
            }
        }
        return res;
    }
};