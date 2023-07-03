class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        int n1 = count(s.begin(), s.end(), '1');   // s 中 '1' 的个数
        long long res = 0;   // 两种子序列的个数总和
        int cnt = 0;   // 遍历到目前为止 '1' 的个数
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                // 010
                res += (long long) (i - cnt) * ((n - n1) - (i - cnt));
                ++cnt;
            } else {
                // 101
                res += (long long) cnt * (n1 - cnt);
            }
        }
        return res;
    }
};
