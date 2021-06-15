class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long res = 0;
        int n = customers.size();
        int stop = 0;
        for (int i = 0; i < n; i++) {
            if (stop < customers[i][0]) stop = customers[i][0];
            stop += customers[i][1];
            res += stop - customers[i][0];
        }
        return 1.0 * res / n;
    }
};
