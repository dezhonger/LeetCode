
// https://leetcode-cn.com/problems/find-array-given-subset-sums/solution/cong-zi-ji-de-he-huan-yuan-shu-zu-by-lee-aj8o/
class Solution {
public:
    vector<int> dfs(int n, vector<int>& s) {
        if (n == 1) {
            if (s[0] == 0) return {s[1]};
            if (s[1] == 0) return {s[0]};
            return {};
        }
        
        // d或者-d至少有一个在原数组中
        
        //d >=0 
        int d = s[1] - s[0];
        int sz = s.size();
        vector<bool> use(sz, false);
        int l = 0, r = 0;
        vector<int> ls, rs;
        while (1) {
            while (l < sz && use[l]) l++;
            if (l == sz) break;
            use[l] = true;
            while (r < sz && (s[r] != s[l] + d || use[r])) r++;
            use[r] = true;
            ls.push_back(s[l]);
            rs.push_back(s[r]);
        }
        //假设d在原数组中,递归求解
        vector<int> ans1 = dfs(n - 1, ls);
        if (ans1.size() > 0) {
            ans1.push_back(d);
            return ans1;
        }
        
        //假设-d在原数组中,递归求解
        vector<int> ans2 = dfs(n - 1, rs);
        if (ans2.size() > 0) {
            ans2.push_back(-d);
            return ans2;
        }
        return {};
    }

    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        return dfs(n, sums);
    }
};
