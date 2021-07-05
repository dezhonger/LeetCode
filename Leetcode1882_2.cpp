typedef pair<int, int> PII;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> res(tasks.size());
        // <权值, id>
        priority_queue<PII, vector<PII>, greater<PII>> idle;
        // <时间, id>
        priority_queue<PII, vector<PII>, greater<PII>> busy;
        
        // 空闲的服务器列表，先选权值小的，相同选id小的
        for (int i = 0; i < servers.size(); i++) idle.push({servers[i], i});
        // 当前时间戳
        int t = 0;
        for (int i = 0; i < tasks.size(); i++) {
            t = max(t, i);
            if (idle.empty()) t = max(t, busy.top().first);
            while (busy.size() && busy.top().first <= t) {
                int id = busy.top().second;
                idle.push({servers[id], id});
                busy.pop();
            }
            //这个时候idle里一定至少有一台服务器
            res[i] = idle.top().second;
            busy.push({t + tasks[i], idle.top().second});
            idle.pop();
        }
        return res;
    }
};
