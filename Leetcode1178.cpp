
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size(), m = puzzles.size();
        unordered_map<int, int> fre;
        for (auto& w: words) {
            int mask = 0;
            for(char ch: w) mask |= (1 << (ch - 'a'));
            if (__builtin_popcount(mask) <= 7) fre[mask]++;
        }
        
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int mask = 0, count = 0;
            for (int j = 1; j < puzzles[i].size(); j++) mask |= (1 << (puzzles[i][j] - 'a'));
            int sub = mask;
            do {
                int s = sub | (1 << (puzzles[i][0] - 'a'));
                count += fre[s];
                sub = (sub - 1) & mask;
            } while (sub != mask);
            res[i] = count;
        }
        return res;
    }
};
