const int N = 1000010;


//下面的数组是后缀数组算法需要定义的
//n是字符串的长度(从1开始), m是字符集的大小
int n, m;
// char s[N];
int s[N];
int sa[N], x[N], y[N], c[N], rk[N], height[N];

//下面的数组是用于该题的
int pos[N];
bool vis[N];
int q;

void get_sa()
{
    for (int i = 1; i <= n; i ++ ) c[x[i] = s[i]] ++ ;
    for (int i = 2; i <= m; i ++ ) c[i] += c[i - 1];
    for (int i = n; i; i -- ) sa[c[x[i]] -- ] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        int num = 0;
        for (int i = n - k + 1; i <= n; i ++ ) y[ ++ num] = i;
        for (int i = 1; i <= n; i ++ )
            if (sa[i] > k)
                y[ ++ num] = sa[i] - k;
        for (int i = 1; i <= m; i ++ ) c[i] = 0;
        for (int i = 1; i <= n; i ++ ) c[x[i]] ++ ;
        for (int i = 2; i <= m; i ++ ) c[i] += c[i - 1];
        for (int i = n; i; i -- ) sa[c[x[y[i]]] -- ] = y[i], y[i] = 0;
        swap(x, y);
        x[sa[1]] = 1, num = 1;
        for (int i = 2; i <= n; i ++ )
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++ num;
        if (num == n) break;
        m = num;
    }
}

void get_height()
{
    //height[i] = lcp(s[sa[i]], s[sa[i - 1]), 也就是说height[1]肯定为0，因为sa[0]不存在的.
    for (int i = 1; i <= n; i ++ ) rk[sa[i]] = i;
    for (int i = 1, k = 0; i <= n; i ++ )
    {
        if (rk[i] == 1) continue;
        if (k) k -- ;
        int j = sa[rk[i] - 1];
        while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k ++ ;
        height[rk[i]] = k;
    }
}


void init(int _n, int _m) {
    //字符串的长度
    n = _n;
    //最大字符集的大小
    m = _m;
    // debug(n, m);

    memset(c, 0, sizeof c);
    // memset(sa, 0, sizeof sa);
    // memset(rk, 0, sizeof rk);
    // memset(height, 0, sizeof height);
    get_sa();
    get_height();
    
    
    // for (int i = 1; i <= n; i++) {
        // cout << "[i, sa[i], height[i]]: " << i << " " << sa[i] << " " << height[i] << " string is ";
        // for (int j = sa[i]; j <= n; j++) cout << s[j] << " ";
        // cout << endl;
    // }
}

class Solution {
public:

    bool check(int mid) {
        //根据height数组的定义, height[1]一定是0
        for (int i = 2; i <= n; i++) {
            if (height[i] < mid) continue;
            int k = i;
            //使用双指针找到连续的一段满足height都大于mid
            while (k <= n && height[k] >= mid) k++;
            // 满足 height[i, k - 1] >= mid
            // 也就是说字符串 s[sa[i-1, i, ...k-2, k-1]的lcp >= mid
            
            //判断一下这中间出现的字符串是否在题目给定的多个串中都出现过
            int cnt = 0;
            for (int j = i - 1; j <= k - 1; j++) {
                //这个字符串对应s中的下标
                int position = sa[j];
                // pos[position]当前这个串的起始位置为对应的是题目给定的哪个串
                int p = pos[position];
                if (p > 0 && !vis[p]) {
                    vis[p] = true;
                    cnt++;
                }
                
            }
            
            for (int j = i - 1; j <= k - 1; j++) {
                //恢复为false, 避免影响下次计算
                vis[pos[sa[j]]] = false;
            }
            
            if (cnt == q) return true;
            
            //双指针算法
            i = k - 1;
        }
        return false;
    }

    int longestCommonSubpath(int _n, vector<vector<int>>& paths) {
        int l = 0, r = 0;
        n = 0, q = paths.size();
        for (int i = 0; i < q; i++) {
            r = max(r, (int)paths[i].size());
            for (int j = 0; j < paths[i].size(); j++) {
                //这里先都加1,和分隔符作为区别。因为s[0] = 0;
                s[++n] = paths[i][j] + 1;
                //记录下生成的字符串中每个位置对应的是原来的哪个字符串
                //加1是因为，那些分隔符默认是存的第0个字符串
                pos[n] = i + 1;
            }
            //每个字符串后加一个分隔符
            s[++n] = _n + i + 1;
            pos[n] = 0;
        }
        
        // for (int i = 0; i <= n; i++) cout << i << " ";
        // cout << endl;
        // for (int i = 0; i <= n; i++) cout << s[i] << " ";
        // cout << endl;
        // for (int i = 0; i <= n; i++) cout << pos[i] << " ";
        // cout << endl;
        
        init(n, _n + paths.size() + 1);
        
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
