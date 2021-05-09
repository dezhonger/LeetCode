class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int res = 0;
        int mi = INT_MAX, ma = INT_MIN;
        for (auto& x: logs) {
            mi = min(mi, x[0]);
            ma = max(ma, x[1]);
        }
        for (int i = mi; i < ma; i++) {
            int r = 0;
            for (auto& x: logs) if (i >= x[0] && i < x[1]) r++;
            res = max(res, r);
        }
        for (int i = mi; i < ma; i++) {
            int r = 0;
            for (auto& x: logs) if (i >= x[0] && i < x[1]) r++;
            if (r == res) return i;
        }
        return 0;
    }
};
