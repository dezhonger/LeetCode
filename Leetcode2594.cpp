class Solution {
public:
    long long repairCars(vector<int> &ranks, int cars) {
        int min_r = *min_element(ranks.begin(), ranks.end());
        long long left = 0, right = 1LL * min_r * cars * cars;
        while (left < right) {
            long long mid = (left + right) / 2, s = 0;
            for (int r : ranks) s += sqrt(mid / r);
            if (s < cars) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
