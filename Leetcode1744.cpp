typedef long long LL;
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = queries.size(), m = candiesCount.size();
        vector<bool> res(n);
        vector<LL> s(m + 1);
        for (int i = 0; i < m; i++) s[i + 1] = s[i] + candiesCount[i];
        for (int i = 0; i < n; i++) {
            int type = queries[i][0] + 1, day = queries[i][1] + 1;
            LL l = s[type - 1] + 1, r = s[type];
            LL ll = day, rr = 1LL * queries[i][2] * day;
            if (day > s[m] || ll > r || rr < l) res[i] = false;
            else res[i] = true;
        }
        return res;
    }
};
