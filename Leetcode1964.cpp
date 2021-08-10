const int N = 100010;
//f[i]: 长度为i的LIS数组的最小结尾数字
int f[N];

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int len = 0, n = obstacles.size();
        vector<int> res(n);
        memset(f, 0, sizeof f);
        f[0] = -2e9;
        for (int i = 0; i < n; i++) {
            int x = obstacles[i];
            int l = 0, r = len;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (f[mid] <= x) l = mid;
                else r = mid - 1;
            }
            f[l + 1] = x;
            len = max(len, l + 1);
            res[i] = l + 1;
        }
        return res;
    }
};
