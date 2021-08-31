const int N = 105;
int f[N][N];
class Solution {
public:
    int cost(int x) {
        if (x == 1) return 1;
        else if (x < 10) return 2;
        else if (x < 100) return 3;
        return 4;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(f, 0x3f, sizeof f);
        //前i个字符删除了j个能得到的压缩串的最短长度 下标都从1开始
        int n = s.size();
        s = ' ' + s;
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(i, k); j++) {
                //删除第i个字符
                if(j) f[i][j] = f[i - 1][j - 1];
                
                //保留第i个字符s[i], 同时保留i前面的与s[i]相等的字符
                int same = 1, diff = 0;
                for (int x = i - 1; x >= 0 && diff <= j; x--) {
                    if (diff <= j) f[i][j] = min(f[i][j], f[x][j - diff] + cost(same));
                    if (s[x] == s[i]) same++;
                    else diff++;
                }
            }
        }
        return f[n][k];
    }
};
