
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& ma, int k) {
        int n = ma.size(), m = ma[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) ma[i][j] ^= ma[i][j - 1];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) ma[j][i] ^= ma[j - 1][i];
        }
        //小根堆
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //cout << ma[i][j] << endl;
                if (pq.size() == k) {
                    if (ma[i][j] > pq.top()) pq.pop();
                }
                if (pq.size() < k) pq.push(ma[i][j]);
                //cout << pq.top() << endl;
            }
        }
        
        return pq.top();
    }
};
