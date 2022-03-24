const int N = 1005;
vector<int> f(N);
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        for (int i = 0; i < n; i++) f[i] = i;
        for (auto r: requests) {
            int x = r[0], y = r[1];
            int fx = find(x), fy = find(y);
            if (fx == fy) ans.push_back(true);
            else {
                bool flag = true;
                for (auto re: restrictions) {
                    int u = find(re[0]), v = find(re[1]);
                    if ((u == fx && v == fy) || (u == fy && v == fx)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) f[fx] = fy;
                ans.push_back(flag);
            }
        }
        return ans;
    }
};
