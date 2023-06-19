const int MX = 1000;
vector<int> primes{0}; // 哨兵，避免二分越界

int init = []() {
    bool np[MX]{};
    for (int i = 2; i < MX; ++i)
        if (!np[i]) {
            primes.push_back(i); // 预处理质数列表
            for (int j = i; j < MX / i; ++j)
                np[i * j] = true;
        }
    return 0;
}();

class Solution {
public:
    bool primeSubOperation(vector<int> &nums) {
        int pre = 0;
        for (int x: nums) {
            if (x <= pre) return false;
            auto it = lower_bound(primes.begin(), primes.end(), x - pre);
            pre = x - *--lower_bound(primes.begin(), primes.end(), x - pre);
        }
        return true;
    }
};
