class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int x: piles) pq.push(x);
        while (k--) {
            int x = pq.top();
            pq.pop();
            pq.push(x - x / 2);
        }
        int res = 0;
        while (pq.size()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
