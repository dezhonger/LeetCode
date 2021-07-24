class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = times.size();
        for (int i = 0; i <= n; i++) pq.push(i);    
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({times[i][0], 1, i});
            v.push_back({times[i][1], 0, i});
        }
        sort(v.begin(), v.end());
        vector<int> mp(n, -1);
        for (int i = 0; i < n * 2; i++) {
            auto cur = v[i];
            if (cur[1] == 1) {
                int t = pq.top();
                mp[cur[2]] = t;
                if (cur[2] == targetFriend) return t;
                pq.pop();
            } else {
                int t = mp[cur[2]];
                pq.push(t);
            }
        }
        return -1;
    }
};
