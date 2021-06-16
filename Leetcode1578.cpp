class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 == n || s[i] != s[i + 1]) continue;
            int j = i, sum = 0, maxV = INT_MIN;
            while (j < n && s[j] == s[i]) sum += cost[j], maxV = max(maxV, cost[j++]);
            res += sum - maxV;
            i = j - 1;
        }
        return res;
    }
};
