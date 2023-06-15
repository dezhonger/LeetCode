class Solution {
public:
    int nn;
    bool check(long long m, vector<int>& q)
    {
        long long c = 0;
        for (int a: q) c += (long long)(a + m - 1) / m;
        return c <= nn;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long sum = accumulate(quantities.begin(), quantities.end(), 0LL);
        long long l = 1, r = sum;
        nn = n;
        while (l < r)
        {
            long long mid = (l + r) >> 1;
            if (check(mid, quantities)) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};
