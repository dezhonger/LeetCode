class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> w1, w2;
        for(auto& s: words1) w1[s]++;
        for(auto& s: words2) w2[s]++;
        int res = 0;
        for (auto [k, v]: w1)
        {
            if (v == 1 && w2[k] == 1) res++;
        }
        return res;
    }
};
