class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res;
        int i = 0, j = 0, l1 = word1.size(), l2 = word2.size();
        while (i < l1 && j < l2) {
            if (word1[i] > word2[j]) res += word1[i++];
            else if (word1[i] < word2[j]) res += word2[j++];
            else {
                if (word1.substr(i) > word2.substr(j)) res += word1[i++];
                else res += word2[j++];
            }
        }
        if (i < l1) res += word1.substr(i);
        if (j < l2) res += word2.substr(j);
        return res;
    }
};
