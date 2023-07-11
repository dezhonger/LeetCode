class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        vector<int> a;
        while (n)
        {
            int m = n & (-n);
            a.push_back(m);
            n ^= m;
        }

        int sz = a.size(), mod = 1e9+7;
        vector<vector<long long>> res(sz, vector<long long>(sz));

        for (int i = 0; i < sz; i++)
        {
            res[i][i] = a[i];
            for (int j = i + 1; j < sz; j++)
            {
                res[i][j] = res[i][j - 1] * a[j] % mod;
            }
        }

        vector<int> ans;
        for (int i = 0; i < q.size(); i++) ans.push_back(res[q[i][0]][q[i][1]]);
        return ans;
    }
};
