class Solution {
public:
    int calWords(string s)
    {
        int result = 1;
        for (char c: s)
        {
            result += c == ' ';
        }

        return result;
    }

    int mostWordsFound(vector<string>& sentences) {
        int result = 0;
        for (string& s: sentences)
        {
            result = max(result, calWords(s));
        }
        return result;
    }
};
