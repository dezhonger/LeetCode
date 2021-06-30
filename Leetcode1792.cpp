class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& x: classes) {
            //v = (x+1)/(y+1) - (x/y)
            double v = 1.0 * (x[1] - x[0]) / (1.0 * x[1] * (x[1] + 1));
            pq.push({v, {x[0], x[1]}});
        }
        while (extraStudents--) {
            auto vv = pq.top();
            pq.pop();
            // cout << vv.first << " " << vv.second.first << " " << vv.second.second << endl;
            vv.second.first++;
            vv.second.second++;
            double x[2];
            x[0] = vv.second.first, x[1] = vv.second.second;
            vv.first = 1.0 * (x[1] - x[0]) / (1.0 * x[1] * (x[1] + 1));
            pq.push(vv);
        }
        double res = 0;
        while (pq.size()) {
            auto vv = pq.top();
            res += 1.0 * vv.second.first / vv.second.second;
            pq.pop();
        }
        return res / n;
    }
};
