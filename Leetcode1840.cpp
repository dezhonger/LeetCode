template<typename T, typename S>
inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }

template<typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        if (restrictions.back()[0] != n) restrictions.push_back({n, n - 1});
        int m = restrictions.size();
        for (int i = 1; i < m; i++) upmin(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        for (int i = m - 2; i >= 0; i--) upmin(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
        int res = 0;
        for (int i = 1; i < m; i++) {
            upmax(res, (restrictions[i - 1][1] + restrictions[i][1] + restrictions[i][0] - restrictions[i - 1][0]) / 2);
        }
        return res;
    }
};
