const int mod = (int)1e9 + 7;
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        typedef long long LL;
        int n = packages.size();
        sort(packages.begin(), packages.end());
        vector<LL> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + packages[i - 1];
        LL res = LLONG_MAX;
        for (int i = 0; i < boxes.size(); i++) {
            sort(boxes[i].begin(), boxes[i].end());
            int m = boxes[i].size();
            if (boxes[i][m - 1] < packages[n - 1]) continue;
            int last = -1;
            LL s = 0;
            for (int j = 0; j < m && last + 1 < n; j++) {
                int l = last + 1, r = n - 1;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (packages[mid] > boxes[i][j]) r = mid - 1;
                    else l = mid;
                }
                if (packages[l] > boxes[i][j]) continue;
                s = s + (LL)(l - last) * boxes[i][j] - (sum[l + 1] - sum[last + 1]);
                last = l;
                
            }
            res = min(res, s);
        }
        if (res == LLONG_MAX) return -1;
        return res % mod;
    }
};
