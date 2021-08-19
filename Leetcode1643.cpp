//https://leetcode-cn.com/problems/kth-smallest-instructions/solution/di-k-tiao-zui-xiao-zhi-ling-by-zerotrac2/
class Solution {
public:
    string ans;
    int f[40][40];
    void dfs(int v, int h, int k) {
        //考虑当前位置放v还是放h
        if (h + v == 0) return ;
        if (h == 0) {
            ans += "V";
            dfs(v - 1, h, k);
            return ;
        }
        
        // 如果当前位置放v，那么比它小的字符串有C(h + v - 1, h - 1)个
        int s = f[h + v - 1][h - 1];
        
        if (k > s) {
            ans += "V";
            dfs(v - 1, h, k - s);
        } else {
            ans += "H";
            dfs(v, h - 1, k);
        }
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        //预处理组合数
        f[0][0] = 1;
        for (int i = 1; i <= 30; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) f[i][j] = 1;
                else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
            }
        }
        ans = "";
        dfs(destination[0], destination[1], k);
        return ans;
        
    }
};
