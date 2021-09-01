const int N = 510;
int g[N][N];
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        memset(g, 0, sizeof g);
        unordered_set<int> us;
        vector<int> v(N, 0);
        vector<int> fa(N, -1);
        int maxV = 0;
        for (auto& e: pairs) {
            int x = e[0], y = e[1];
            g[x][y] = g[y][x] = 1;
            us.insert(x);
            us.insert(y);
            v[x]++;
            v[y]++;
            maxV = max(maxV, max(x, y));
        }
        vector<vector<int>> vv;
        int n = us.size();
        for (int i = 1; i <= maxV; i++) {
            if (us.count(i)) vv.push_back({i, v[i]});
        }
        //按照度数排序
        sort(vv.begin(), vv.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int maxDegree = vv[vv.size() - 1][1];
        if (maxDegree != n - 1) {
            //这个应该是根节点，它的度数是n-1才可能有答案
            return 0;
        }
        
        // debug(vv);
        // 记录是否有两个有关系的节点的度数相同
        bool two = false;
        
        for (int i = n - 1; i >= 0; i--) {
            int x = vv[i][0];
            // debug(i,x);
            //两个节点有关系的条件是父亲的度数要 >= 儿子的度数，当两者之间是一条链的时候取等号
            for (int j = 0; j < i; j++) {
                int y = vv[j][0];
                if (g[x][y]) {
                    if (v[x] == v[y]) two |= true;
                    fa[y] = x;
                }
            }
        }
        // debug(fa);        
        // 统计父子关系节点的数量
        int t = 0;
        for (int x: us) {
            int j = fa[x];
            while (j != -1) {
                t++;
                j = fa[j];
            }
        }

        // debug(t);
        if (t != pairs.size()) return 0;
        return 1 + two;
    }
};
