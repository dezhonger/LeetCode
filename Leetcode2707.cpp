class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> us(dictionary.begin(), dictionary.end());
        vector<int> f(n + 1, INT_MAX);
        f[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                string str = s.substr(j, i - j);
                if (us.count(str)) f[i] = min(f[i], f[j]);
                else f[i] = min(f[i], f[j] + i - j);
            }
        }
        return f[n];
    }
};
