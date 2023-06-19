class Solution {
public:
    long long makeSubKSumEqual(vector<int> &arr, int k) {
        int n = arr.size();
        k = gcd(k, n);
        vector<vector<int>> g(k);
        for (int i = 0; i < n; ++i) g[i % k].push_back(arr[i]);
            
        long long ans = 0;
        for (auto &b: g) {
            nth_element(b.begin(), b.begin() + b.size() / 2, b.end());
            for (int x: b) ans += abs(x - b[b.size() / 2]);
        }
        return ans;
    }
};
