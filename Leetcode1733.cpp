
const int N = 510;
int f[N][N];

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        memset(f, 0, sizeof f);
        for (int i = 0; i < languages.size(); i++) {
            for (int j: languages[i]) f[i + 1][j] = 1;
        }
        
        // 维护不能交流的人对
        vector<vector<int>> v;
        for (auto& x: friendships) {
            int u = x[0], vv = x[1];
            int ok = 0;
            for (int j = 1; !ok && j <= n; j++) {
                if (f[u][j] && f[vv][j]) {
                    ok = 1;
                }
            }
            if (!ok) v.push_back(x);
        }
        
        // 枚举教哪个语言答案最小
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            unordered_set<int> s;
            for (auto& x : v) {
                if (!f[x[0]][i]) s.insert(x[0]);
                if (!f[x[1]][i]) s.insert(x[1]);
            }
            ans = min(ans, (int)s.size());
        }
        return ans;
    }
};
