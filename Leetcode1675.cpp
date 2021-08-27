
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minV = INT_MAX;
        for (int& x: nums) {
            int t = (x & 1) ? (x << 1) : x;
            pq.push(t);
            minV = min(minV, t);
        }
        int res = pq.top() - minV;
        // 现在pq里全都是偶数，只用考虑操作1即可。 并且只有是把最大数的变小，才有可能更新答案
        while (pq.size() && !(pq.top() & 1)) {
            int t = pq.top();
            pq.pop();
            pq.push(t >> 1);
            minV = min(minV, t >> 1);
            res = min(res, pq.top() - minV);
        }
        return res;
    }
};
