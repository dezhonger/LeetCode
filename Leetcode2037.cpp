class Solution {
public:
    int minMovesToSeat(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int s = 0, n = a.size();
        for (int i = 0; i < n; i++) s += abs(a[i] - b[i]);
        return s;
    }
};
