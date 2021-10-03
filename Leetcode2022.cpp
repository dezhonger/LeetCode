class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return vector<vector<int>>();
        vector<vector<int>> s(m, vector<int>(n));
        for (int i = 0; i < original.size(); i++) s[i / n][i % n] = original[i];
        return s;
    }
};
