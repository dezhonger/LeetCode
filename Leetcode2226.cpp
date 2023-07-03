class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        auto check = [&](int i) -> bool {
            long long res = 0;
            for (int c: candies) res += c / i;
            return res >= k;
        };

        int l = 0, r = *max_element(candies.begin(), candies.end());
        while (l < r) {
            int mid = (1 + l + r) / 2;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
