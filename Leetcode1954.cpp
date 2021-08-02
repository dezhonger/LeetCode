
typedef long long LL;
class Solution {
public:
    LL cal(LL m) {
        LL res = 0;
        for (LL i = 0, j = 1; i <= m; i++, j++) res += i * j;
        for (LL i = 1, j = m; i <= m; i++, j--) res += (i + m) * j;
        return res * 4 - m * (m + 1) * 2;
    }
    long long minimumPerimeter(long long neededApples) {
        LL l = 1, r = (LL)pow(neededApples, 1.0 / 3) + 1;
        while (l < r) {
            LL mid = l + r >> 1;
            LL x = cal(mid);
            if (x >= neededApples) r = mid;
            else l = mid + 1;
        }
        return l * 8;
    }
};
