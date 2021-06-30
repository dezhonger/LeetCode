class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        for (int i = 1; i < n; i++) {
            int d = heights[i - 1] - heights[i];
            if (d >= 0) continue;
            d = -d;
            if (bricks >= d) {
                bricks -= d;
                pq.push(d);
            } else if (ladders > 0) {
                if (pq.size()) {
                    int maxV = pq.top();
                    if (d < maxV) {
                        pq.pop();
                        ladders--;
                        bricks += maxV;
                        bricks -= d;
                        pq.push(d);
                    } else {
                        ladders--;
                    }
                } else {
                    ladders--;
                }
            } else {
                return i - 1;
            }
        }
        return n - 1;
    }
};
