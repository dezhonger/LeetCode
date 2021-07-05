struct Node1 {
    //空闲的服务器
    int id, w, t;
    bool operator< (const Node1& other) const {
        //选择权重最小，权重相同选择id最小的服务器
        if (w != other.w) return w > other.w;
        return id > other.id;
    }
};

struct Node2 {
    //忙碌的服务器
    int id, w, t;
    bool operator< (const Node2& other) const {
        //最早结束的，权重最小的，id最小的服务器
        if (t != other.t) return t > other.t;
        if (w != other.w) return w > other.w;
        return id > other.id;
    }
};

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size(), n = tasks.size();
        vector<int> res(n);
        priority_queue<Node1> idle;
        priority_queue<Node2> busy;
        for (int i = 0; i < m; i++) idle.push({i, servers[i], 0});
        for (int i = 0; i < n; i++) {
            while (busy.size() && busy.top().t <= i) {
                auto c = busy.top();
                busy.pop();
                idle.push({c.id, c.w, c.t});
            }
            if (idle.size()) {
                auto c = idle.top();
                idle.pop();
                res[i] = c.id;
                busy.push({c.id, c.w, i + tasks[i]});
            } else {
                auto c = busy.top();
                busy.pop();
                res[i] = c.id;
                busy.push({c.id, c.w, c.t + tasks[i]});
            }
        }
        return res;
    }
};
