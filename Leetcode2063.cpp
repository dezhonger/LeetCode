class Solution {
public:
    long long countVowels(string words) {
        int n = words.size();
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (words[i] == 'a' || words[i] == 'e' || words[i] == 'i' || words[i] == 'o' || words[i] == 'u')
            {
                res += (long long)(i + 1) * (n - i);
            }
        }
        return res;
    }
};
