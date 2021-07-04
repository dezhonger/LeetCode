class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<int,vector<int>,greater<int> > pq;
        int n = dist.size();
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            int a = dist[i], b = speed[i];
            t[i] = (a + b - 1) / b;
        }
        vector<pair<int, int>> q(n);
        for (int i = 0; i < n; i++) q[i] = {t[i], i};
        sort(q.begin(), q.end());
        int ans = 1;
        for (int i = 1; i < n; i++) {
            int k = q[i].second;
            int d = dist[k] - speed[k] * i;
            if (d <= 0) break;
            else ans++;
        }
        return ans;
    }
};
