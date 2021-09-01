class Solution {
public:
    double get(double x, double y, vector<vector<int>>& pp) {
        double s = 0;
        for (auto& p: pp) s += sqrt((x - p[0]) * (x - p[0]) + (y - p[1]) * (y - p[1]));
        return s;
    }
    
    double cal(double x, vector<vector<int>>& positions) {
        double l = 0, r = 100;
        while (r - l > 1e-6) {
            double mid1 = l + (r - l) / 3, mid2 = l + (r - l) / 3 * 2;
            if (get(x, mid1, positions) > get(x, mid2, positions)) l = mid1;
            else r = mid2;
        }
        return get(x, l, positions);
        
    }

    double getMinDistSum(vector<vector<int>>& positions) {
        double l = 0, r = 100;
        while (r - l > 1e-6) {
            double mid1 = l + (r - l) / 3, mid2 = l + (r - l) / 3 * 2;
            if (cal(mid1, positions) > cal(mid2, positions)) l = mid1;
            else r = mid2;
        }
        return cal(l, positions);
    }
};
