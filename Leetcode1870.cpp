class Solution {
public:
    bool check(int s, vector<int>& d, double h) {
        double res = 0;
        for (int i = 0; i < d.size() - 1; i++) {
            res += (d[i] + s - 1) / s;
        }
        res += 1.0 * d.back() / s;
        return res <= h;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (n - 1 >= hour) return -1;
        int l = 1, r = 1000000000;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, dist, hour)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
