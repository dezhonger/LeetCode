typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef long long LL;

int mod = (int)1e9 + 7;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        LL s = 0, c = INT_MAX, cnt = 0;
        for (auto& x: matrix) {
            for (auto& y: x) {
                s += abs(y);
                c = min(c, abs(((LL)y)));
                if (y < 0) cnt++;
            }
        }
        if (cnt % 2 == 1) return s - 2 * c;
        else return s;
    }
};
