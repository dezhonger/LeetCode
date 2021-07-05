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
        
        int maxV1 = -1e8;
        int maxV2 = -1e8;
        int maxV3 = -1e8;
        int maxV4 = -1e8;
        for (int r = 1; r < n - 1; r++) {
            int v1 = -abs(a[r] - a[r + 1]) - (+ a[r] + a[r + 1]);
            int v2 = -abs(a[r] - a[r + 1]) - (+ a[r] - a[r + 1]);
            int v3 = -abs(a[r] - a[r + 1]) - (- a[r] + a[r + 1]);
            int v4 = -abs(a[r] - a[r + 1]) - (- a[r] - a[r + 1]);
            
            res = max(res, init + v1 + maxV1);
            res = max(res, init + v2 + maxV2);
            res = max(res, init + v3 + maxV3);
            res = max(res, init + v4 + maxV4);
            
            int w1 = -abs(a[r] - a[r - 1]) + a[r - 1] + a[r];
            int w2 = -abs(a[r] - a[r - 1]) + a[r - 1] - a[r];
            int w3 = -abs(a[r] - a[r - 1]) - a[r - 1] + a[r];
            int w4 = -abs(a[r] - a[r - 1]) - a[r - 1] - a[r];
            maxV1 = max(maxV1, w1);
            maxV2 = max(maxV2, w2);
            maxV3 = max(maxV3, w3);
            maxV4 = max(maxV4, w4);
            
        }
        
        return res;
    }
};
