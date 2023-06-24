const int MX = 1e6;
vector<int> primes;

int init = []() {
    bool np[MX + 1]{};
    for (int i = 2; i <= MX; ++i)
        if (!np[i]) {
            primes.push_back(i);
            for (int j = i; j <= MX / i; ++j) // 避免溢出的写法
                np[i * j] = true;
        }
    primes.push_back(MX + 1);
    primes.push_back(MX + 1); // 保证下面下标不会越界
    return 0;
}();

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int p = -1, q = -1;
        int i = lower_bound(primes.begin(), primes.end(), left) - primes.begin();
        for (; primes[i + 1] <= right; ++i)
            if (p < 0 || primes[i + 1] - primes[i] < q - p) {
                p = primes[i];
                q = primes[i + 1];
            }
        return {p, q};
    }
};
