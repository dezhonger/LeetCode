typedef pair<int, int> PII;


class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int res = 0, n = apples.size();
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for (int i = 0; i < n; i++) {
            if (apples[i]) pq.push({i + days[i] - 1, apples[i]});
            while (pq.size()) {
                auto cur = pq.top();
                // 已经腐烂了
                if (cur.first < i) pq.pop();
                else break;
            }
            if (pq.size()) {
                auto cur = pq.top();
                cur.second--;
                res++;
                pq.pop();
                if (cur.second) pq.push(cur);
            }
        }
        // 当前是第n天
        int d = n;
        while (pq.size()) {
            while (pq.size()) {
                auto cur = pq.top();
                // 已经腐烂了
                if (cur.first < d) pq.pop();
                else break;
            }
            if (pq.size()) {
                auto cur = pq.top(); 
                // 能吃到的苹果数量
                int can = min(cur.second, cur.first - d + 1);
                res += can;
                d += can;
                pq.pop();
            }
        }
        return res;
    }
};
