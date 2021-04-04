const int N = 2e5 + 10;
const int M = 2e5;
bool v[N], cnt[N];
class Solution {
public:
    
    
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        //考虑每个数x是否可能是答案
        
        //对于每个数x，如果它可能成为答案的充要条件是：有一些x的倍数，这些数的gcd为x
        memset(v, 0, sizeof v);
        memset(cnt, 0, sizeof cnt);
        for (int x : nums) cnt[x] = 1;
        int res = 0;
        for (int i = 1; i <= M; i++) {
            int g = 0;
            for (int j = i; j <= M; j += i) {
                if (cnt[j]) g = __gcd(g, j);
                if (g == i) break;
            }
            if (g == i) res++;
        }
        return res;

        
    }
};
