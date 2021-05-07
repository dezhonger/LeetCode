class Solution {
public:
    int threeSumClosest(vector<int>& a, int t) {
        int n = a.size();
        pair<int, int> res = {INT_MAX, INT_MAX};
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1, k = n - 1; j < k; j++) {
                while (j + 1 < k && a[i] + a[j] + a[k - 1] >= t) k--;
                int s = a[i] + a[j] + a[k];
                //这里需要加绝对值，因为有可能初始的i, j, k的和就小于t了
                res = min(res, {abs(s - t), s});
                if (k - 1 > j) {
                    s = a[i] + a[j] + a[k - 1];
                    res = min(res, {t - s, s});
                }
            }
        }
        return res.second;
    }
};