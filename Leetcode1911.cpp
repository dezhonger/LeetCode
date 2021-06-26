typedef long long LL;
int mod = (int)1e9 + 7;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        int n = a.size();
        LL mvF = 0, mvG = -1e8;
        for (int i = 1; i <= n; i++) {
            LL f = max(mvG + a[i - 1], 1LL * a[i - 1]);
            LL g = mvF - a[i - 1];
            mvF = max(mvF, f);
            mvG = max(mvG, g);
        }

        return mvF;
    }
};
