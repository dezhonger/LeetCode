struct Request {
    int st, ed, idx;
    Request(int st_, int ed_, int idx_):st(st_), ed(ed_), idx(idx_){}
    bool operator < (const Request &another) const {
        //按照开始时间从小到大排序
        return st < another.st;
    }
};

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = load.size(), j;
        set<Request> s;
        vector<int> c(k, 0), finish(k, 0);
        for (int i = 0; i < n + k; i++) {
            if (i < n) {
                s.insert({arrival[i], arrival[i] + load[i], i});
            }
            j = i % k;
            while (1) {
                // 找第j个服务器能处理的请求
                auto it = s.lower_bound({finish[j], -1, -1});
                if (it == s.end()) break;
                c[j]++;
                finish[j] = it -> ed;
                s.erase(it);
            }
        }
        int maxV = *max_element(c.begin(), c.end());
        vector<int> res;
        for (int i = 0; i < k; i++) if (c[i] == maxV) res.push_back(i);
        return res;
    }
};
