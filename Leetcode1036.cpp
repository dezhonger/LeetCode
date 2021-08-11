#define F first
#define S second


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

const LL N = 1000000;

class Solution {
public:
    int m;
    unordered_set<LL> us;
    int search(vector<int>& source, vector<int>& target) {
        queue<PII> q;
        set<LL> s;
        q.push({source[0], source[1]});
        s.insert(N * source[0] + source[1]);
        while (q.size()) {
            auto c = q.front();
            q.pop();
            if (c.F == target[0] && c.S == target[1]) return 1;
             if (s.size() > (1 + m) * (1 + m) / 2) return 2;
            for (int k = 0; k < 4; k++) {
                int x = c.F + dx[k], y = c.S + dy[k];
                if (x >= 0 && y >= 0 && x < N && y < N) {
                    LL t = N * x + y;
                    //没有被搜过且不是障碍
                    if (s.find(t) == s.end() && us.count(t) == 0) {
                        s.insert(t);
                        q.push({x, y});
                    }
                }
            }
        } 
        return 0;
    }
    
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        m = blocked.size();
        // m个block大约最多可以围住m^2/2个位置(在一个角里)
        for (auto& b: blocked) us.insert(b[0] * N + b[1]);
        // 如果起点和终点都超过了这么多可达的格子，则一定能从起点到终点。 (注意是都)
        
        int res1 = 0, res2 = 0;
        res1 = search(source, target);
        if (res1 == 1) return true;
        res2 = search(target, source);
        if (res2 == 1) return true;
        if (res1 == 2 && res2 == 2) return true;
        return false;
    }
};
