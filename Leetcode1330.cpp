// 展开绝对值，分四种情况讨论 https://leetcode-cn.com/problems/reverse-subarray-to-maximize-array-value/solution/onzuo-fa-jie-jue-ci-wen-ti-by-hu-tu-tu-7/
class Solution {
public:
    int maxValueAfterReverse(vector<int>& a) {
        int n = a.size();
        int res = 0, init = 0;
        for (int i = 1; i < n; i++) init += abs(a[i] - a[i - 1]);
        res = max(res, init);
        for (int i = 1; i < n - 1; i++) {
            // 翻转[0, i]
            int delta = abs(a[0] - a[i + 1]) - (abs(a[i] - a[i + 1]));
            res = max(res, init + delta);
        }
        for (int i = 1; i < n - 1; i++) {
            // 翻转[i, n - 1]
            int delta = abs(a[i - 1] - a[n - 1]) - abs(a[i - 1] - a[i]);
            res = max(res, init + delta);
        }
        
        for (int f1 : {-1, 1}) {
            for (int f2: {-1, 1}) {
                int maxV = -1e8;
                for (int r = 1; r < n - 1; r++) {
                    int v = -abs(a[r] - a[r + 1]) - (f1 * a[r] + f2 * a[r + 1]);
                    res = max(res, init + v + maxV);
                    maxV = max(maxV, -abs(a[r] - a[r - 1]) + (f1 * a[r - 1] + f2 * a[r]));
                }
            }
        }
        return res;
    }
};
