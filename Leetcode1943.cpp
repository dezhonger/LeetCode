class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& s) {
        typedef long long LL;
        int n = s.size(), rr = 0, ll = INT_MAX;
        vector<LL> c(100010);
        vector<LL> d(100010);
        int k = 1;
        for (auto& x: s) {
            int l = x[0], r = x[1], v = x[2];
            c[l] += v;
            c[r] -= v;
            rr = max(r, rr);
            ll = min(l, ll);
            
            d[l] += k;
            d[r] -= k;
            k++;
        }
        vector<vector<long long>> ans;
        for (int i = 1; i <= rr; i++) {
            c[i] += c[i - 1];
            d[i] += d[i - 1];
        }
        for (int i = ll; i < rr; i++) {
            LL v = c[i], w = d[i];
            int j = i;
            while (j < rr && c[j] == v && d[j] == w) j++;
            if (v) ans.push_back({i, j, v});
            i = j - 1;
        }
        return ans;
    }
};
