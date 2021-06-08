class Solution {
public:
    bool checkZeroOnes(string s) {
        int z1 = 0, z2 = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            if (s[i] == '1') z1 = max(z1, j - i);
            else z2 = max(z2, j - i);
            i = j -1;
        }
        return z1 > z2;
    }
};
