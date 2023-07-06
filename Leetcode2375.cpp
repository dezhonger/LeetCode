class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string s(n + 1, '0');
        iota(s.begin(), s.end(), '1');
        for(int i = 0; i < n; ++i){
            int t = i;
            while(i < n && pattern[i] == 'D') ++i;
            reverse(s.begin() + t, s.begin() + i + 1);
        }
        return s;
    }
};
