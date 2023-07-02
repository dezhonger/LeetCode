class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        int maxscore = 0;   // 可行的最大得分
        int state = 0;   // 对应状态
        // 枚举所有输赢状态
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cnt = 0;
            int score = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    cnt += aliceArrows[i] + 1;
                    score += i;
                }
            }
            if (cnt <= numArrows && score > maxscore) {
                // 可行，且更新了当前最大得分
                maxscore = score;
                state = mask;
            }
        }
        // 通过状态构造一种可行方法
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            if ((state >> i) & 1) {
                res[i] = aliceArrows[i] + 1;
                numArrows -= res[i];
            }
        }
        res[0] += numArrows;
        return res;
    }
};
