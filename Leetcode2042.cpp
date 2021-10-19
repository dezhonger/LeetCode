class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size(), last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue;
            int j = i;
            while (j < n && s[j] != ' ') j++;
            string str = s.substr(i, j - i);
            if (isdigit(str[0])) {
                int v = stoi(str);
                if (v <= last) return false;
                last = v;
            }
            i = j;
        }
        return true;
    }
};
