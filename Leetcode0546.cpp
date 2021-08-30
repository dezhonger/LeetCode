//https://leetcode-cn.com/problems/remove-boxes/solution/yi-chu-he-zi-by-leetcode-solution/
const int N = 110;
int f[N][N][N];
class Solution {
public:
    int cal(int l, int r, int k, vector<int>& boxes) {
        if (l > r) return 0;
        // f[l][r][k] 删除[l, r]区间以及r后面和a[r]颜色相同的k个木块所得到的最大分数
        if (f[l][r][k] != -1) return f[l][r][k];
        
        int r1 = r - 1, k1 = k;
        while (r1 > l && boxes[r1] == boxes[r]) r1--, k1++;
        
        f[l][r][k] = cal(l, r1, 0, boxes) + (k1 + 1) * (k1 + 1);
        for (int i = l; i <= r1; i++) {
            if (boxes[i] == boxes[r]) {
                f[l][r][k] = max(f[l][r][k], 
                    cal(i + 1, r1, 0, boxes) + cal(l, i, k1 + 1, boxes));
            }
        }
        return f[l][r][k];
        
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(f, -1, sizeof f);
        return cal(0, n - 1, 0, boxes);
    }
};
