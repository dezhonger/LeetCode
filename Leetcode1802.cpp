typedef long long LL;
int mod = (int)1e9 + 7;

class Solution {
public:
    LL get(int v, int c) {
        if (v == 0) return c;
        LL s = 0;
        if (c >= v) {
            s = 1LL * v * (v + 1) / 2;
            s += c - v;
        } else {
            s = 1LL * (v + v - c + 1) * c / 2;
        }
        return s;
    }

    bool check(int v, int index, int n, LL maxSum) {
        LL s = v;
        //    1,1,1... v - 3, v - 2, v - 1, v, v - 1, v - 2, v - 3, .... 1,1,1
        int leftCnt = index, rightCnt = n - index - 1;
        LL ls = get(v - 1, leftCnt), rs = get(v - 1, rightCnt);
        return s + ls + rs <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid, index, n, maxSum)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
