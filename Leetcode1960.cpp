typedef long long LL;


const int maxn = 1e5 + 5;
const int N = 26;
struct Palindromic_Tree {
    int next[maxn][N];
    int fail[maxn];
    int cnt[maxn];//第i个节点表示的回文串出现的次数，最后要调用count函数完成计算
    int num[maxn];//以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数
    int len[maxn];//节点i表示的回文串的长度
    int S[maxn];//存放添加的字符
    int last;
    int n;//字符数组指针
    int p;//节点指针
    int newnode (int l) {
        memset (next[p], 0, sizeof next[p]);
        cnt[p] = 0;
        num[p] = 0;
        len[p] = l;
        return p++;
    }
    void init() {
        p = 0;
        newnode (0);
        newnode (-1);
        last = 0;
        n = 0;
        S[n] = -1;
        fail[0] = 1;
    }
    int get_fail (int x) {
        while (S[n - len[x] - 1] != S[n])
            x = fail[x];
        return x;
    }
    int add (int c) {
        c -= 'a';
        S[++n] = c;
        int cur = get_fail (last);
        if (!next[cur][c]) { //如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int now = newnode (len[cur] + 2);
            fail[now] = next[get_fail (fail[cur])][c];
            next[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = next[cur][c];
        cnt[last]++;
        //返回当前这个节点对应的回文串的长度
        return len[last];
    }
    void count() {
        for (int i = p - 1; i >= 0; i--)
            cnt[fail[i]] += cnt[i];
    }
} pam1, pam2;


class Solution {
public:
    long long maxProduct (string s) {
        int n = s.size();
        pam1.init();
        pam2.init();
        vector<int> v1 (n), v2 (n);
        long long res = 0;
        for (int i = 0; i < n; i++) {
            v1[i] = pam1.add (s[i]);
            if (v1[i] % 2 == 0)
                v1[i] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            v2[i] = pam2.add (s[i]);
            if (v2[i] % 2 == 0)
                v2[i] = 0;
        }
        for (int i = 1; i < n; i++)
            v1[i] = max (v1[i], v1[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            v2[i] = max (v2[i], v2[i + 1]);
        for (int i = 1; i < n; i++) {
            res = max (res, 1LL * v1[i - 1] * v2[i]);
        }
        return res;
    }
};
