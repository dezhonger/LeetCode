class Solution {
public:
    int divide(int dividend, int divisor) {
        vector<LL> d;
        int f = 1;
        if (divisor > 0 && dividend < 0) f = -1;
        if (divisor < 0 && dividend > 0) f = -1;
        LL a = abs(dividend), b = abs(divisor);
        for (LL i = b; i <= a; i = i + i) {
            d.push_back(i);
        }
        LL res = 0;
        for (int i = d.size() - 1; i >= 0; i--) {
            if (a >= d[i]) {
                a -= d[i];
                res += 1LL << i;
            }
        }
        res *= f;
        if (res > INT_MAX || res < INT_MIN) res = INT_MAX;
        return res;
    }
};

