class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> c1, c2;
        for (char c: word1) ++c1[c];
        for (char c: word2) ++c2[c];
        for (auto[x, c] : c1)
            for (auto[y, d] : c2)
                if (y == x) {
                    // 交换x和y
                    if (c1.size() == c2.size()) return true; 
                } else if (c1.size() - (c == 1) + !c1.count(y) ==
                           c2.size() - (d == 1) + !c2.count(x)) // 基于长度计算变化量
                           // 交换x和y
                    return true;
        return false;
    }
};
