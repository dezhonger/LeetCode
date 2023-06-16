class Solution {
public:
    long long maxScore = 0;
    int cnt = 0, n;
    vector<vector<int>> child;

    int dfs(int node)
    {
        long long score = 1;
        int cc = 1;
        for (int c: child[node])
        {
            int t = dfs(c);
            cc += t;
            score *= t;
        }

        if (node != 0) score *= (n - cc);

        if (score == maxScore) cnt++;
        else if (score > maxScore) maxScore = score, cnt = 1;
        return cc;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        this -> n = parents.size();
        this -> child = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) if (parents[i] != -1) child[parents[i]].emplace_back(i);
        dfs(0);
        return cnt;
    }
};
