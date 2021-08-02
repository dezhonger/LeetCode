class Solution {
public:
    long long numberOfWeeks(vector<int>& a) {
        long long res = 0;
        sort(a.begin(), a.end());
        long long q = accumulate(a.begin(), a.end() - 1, 0LL);
        long long s = a.back();
        if (s <= q) return q + s;
        else return q * 2 + 1;
    }
};
