class Solution {
public:
    int countBeautifulPairs(vector<int> &nums) {
        int ans = 0, cnt[10]{};
        for (int x: nums) {
            for (int y = 1; y < 10; y++)
                if (cnt[y] && gcd(x % 10, y) == 1)
                    ans += cnt[y];
            while (x >= 10) x /= 10; // 这里需要 O(log x) 的时间
            cnt[x]++; // 统计最高位的出现次数
        }
        return ans;
    }
};
