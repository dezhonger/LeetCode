class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> res;
        int n = a.size();
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            //去掉重复方案
            if (i > 0 && a[i] == a[i - 1]) continue;
            for (int j = i + 1, k = n - 1; j < k; j++) {
                //去掉重复方案
                if (j > i + 1 && a[j] == a[j - 1]) continue ;
                //找到>=k的第一个数,同时去掉重复的k的方案
                while (j + 1 < k && a[i] + a[j] + a[k - 1] >= 0) k--;
                if (a[i] + a[j] + a[k] == 0) res.push_back({a[i], a[j], a[k]});
            }
        }
        return res;
    }
};
