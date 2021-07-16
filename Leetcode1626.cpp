#define F first
#define S second


int mod = (int)1e9 + 7;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size(), ans = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) v.emplace_back(make_pair(ages[i], scores[i]));
        sort(v.begin(), v.end());
        vector<int> f(n, 0);
        for (int i = 0; i < n; i++) {
            f[i] = v[i].S;
            for (int j = 0; j < i; j++) {
                if (v[j].S <= v[i].S) f[i] = max(f[i], f[j] + v[i].S);
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
