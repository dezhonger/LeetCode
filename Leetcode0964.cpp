#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int ans;
    
    inline int get(int depth) {
        return depth == 0 ? 1 : depth - 1;
    }

    void dfs(int x, int t, int depth, int result, int use) {
        //cout << "x: " << x << " t: " << t << " depth:" << depth << " result:" << result << " use:" << use << endl;
        //if (depth >= 30) return ;
        if (t == 0) {
            //不同进制下需要depth-1个加号或者减号连接起来
            ans = min(result + max(0, use - 1), ans);
            return ;
        }
        if (t == 1) {
            //不同进制下需要depth-1个加号或者减号连接起来, t=1表示当前也需要一个数
            ans = min(result + get(depth) + use, ans);
            return ;
        }

        int remain = t % x;
        int remain2 = x - remain;
        int need = get(depth);
        //(remain - 1)表示需要remain-1个加号，need * remain需要remain个x相乘,比如5*5+5*5 remain=2, need = 1,depth=2
        dfs(x, t / x,     depth + 1, result + max(0, (remain - 1)) + need * remain, use + (remain > 0 ? 1 : 0));
        if (remain != 0)
            dfs(x, t / x + 1, depth + 1, result + max(0, (remain2 - 1)) + need * remain2, use + (remain2 > 0 ? 1 : 0));
            
    }

    int leastOpsExpressTarget(int x, int target) {
        ans = 0x3f3f3f3f;
        dfs(x, target, 0, 0, 0);
        return ans;

    }
};

int main() {
    Solution s;
    cout << s.leastOpsExpressTarget(2, 125046) << endl;
    cout << s.leastOpsExpressTarget(2, 21125019) << endl;
    cout << s.leastOpsExpressTarget(100, 1) << endl;
    cout << s.leastOpsExpressTarget(3, 19) << endl;
    cout << s.leastOpsExpressTarget(5, 501) << endl;
    cout << s.leastOpsExpressTarget(100, 100000000) << endl;
    return 0;
}


