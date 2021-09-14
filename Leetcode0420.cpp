class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size(), a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (isdigit(password[i])) a = 1;
            else if (isupper(password[i])) b = 1;
            else c = 1;
        }
        int k = a + b + c;
        if (n < 6) return max(6 - n, 3 - k);

        int p = 0, d[3] = {0};
        for (int i = 0; i < n; i++) {
            char ch = password[i];
            int j = i;
            while (j < n && password[j] == ch) j++;
            int sz = j - i;
            p += sz / 3;
            if (sz >= 3) d[sz % 3] ++;
            i = j - 1;
        }
        if (n <= 20) return max(3 - k, p);
        
        int del = n - 20, ans = del;
        if (del && d[0]) {
            int x = min(d[0], del);
            p -= x;
            del -= x;
        }
        if (del && d[1]) {
            int x = min(d[1], del / 2);
            p -= x;
            del -= x * 2;
        }
        if (del && p) {
            int x = min(p, del / 3);
            p -= x;
        }
        return ans + max(p, 3 - k);
    }
};
