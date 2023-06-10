class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> v(26, -0);
        for (int i = 0, ch = 1; ch <= 26 && i < key.size(); i++)
        {

            if (!isalpha(key[i])) continue;
            if (!v[key[i] - 'a']) v[key[i] - 'a'] = ch++;
        }

        string res;
        for (char ch : message)
        {
            if (!isalpha(ch)) res += ch;
            else res.push_back(v[ch - 'a'] + 'a' - 1);
        }

        return res;
    }
};
