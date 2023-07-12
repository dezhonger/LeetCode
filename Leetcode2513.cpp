class Solution {
public:
    int minimizeSet(int d1, int d2, int uniqueCnt1, int uniqueCnt2) {
        long long lcm = 1LL * d1 * d2 / gcd(d1, d2);
        int l = 1, r = (uniqueCnt1 + uniqueCnt2) * 2;
        auto check = [&](int x) -> bool
        {
            long long a = max(0LL, uniqueCnt1 - x / d2 + x / lcm);
            long long b = max(0LL, uniqueCnt2 - x / d1 + x / lcm);
            long long c = x - x / d1 - x / d2 + x / lcm;
            return c >= a + b;
        };
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
