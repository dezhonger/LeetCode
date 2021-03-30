#define ps push_back
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> v;
        for (int x : nums) v.ps(x);
        return dfs(v);
    }
    
    vector<double> cal(vector<double> v, int x, int y, double num) {
        vector<double> vv;
        vv.ps(num);
        for (int i = 0; i < v.size(); i++) {
            if (i != x && i != y) {
                vv.ps(v[i]);
            }
        }
        return vv;
    }
    
    bool dfs(vector<double> v) {
        int sz = v.size();
        if (sz == 1) return fabs(v[0] - 24) <= 1e-6;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (i == j) continue;
                double a = v[i], b = v[j];
                if (dfs(cal(v, i, j, a + b))) return true;
                if (dfs(cal(v, i, j, a - b))) return true;
                if (dfs(cal(v, i, j, a * b))) return true;
                if (b != 0 && dfs(cal(v, i, j, a / b))) return true;
            }
        }
        return false;
    }
    
};