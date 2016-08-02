#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//这个题目本来看成一个矩形嵌套那个题目了，结果这个题目要求长和宽不能交换，看了出错数据才知道。。直接记忆化搜索即可。
class Solution {
public:
    vector<int> dp;
    int ans = -1, len;
    bool can(pair<int, int> a, pair<int, int> b) {
        return (a.first > b.first && a.second > b.second);
    }
    int dfs(vector<pair<int, int>>& envelopes, int index) {
        if(dp[index] != -1) return dp[index];
        dp[index] = 1;
        for(int i = index + 1; i < len; i++) {
            if(can(envelopes[index], envelopes[i])) {
                dp[index] = max(dp[index], 1 + dfs(envelopes, i));

            }
        }
        return dp[index];
    }
    struct cmpfun {
        bool operator()(const pair<int, int>& A, const pair<int, int>& B) {
            return A.first > B.first || (A.first == B.first && A.second > B.second);
        }
    };

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        len = envelopes.size();
        if(len == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), cmpfun());
        for(int i = 0; i < len; i++) dp.push_back(-1);
        for(int i = 0; i < len; i++) {
            ans = max(ans, dfs(envelopes, i));
        }
        return ans;
    }
};

int main()
{
    vector<pair<int, int>> envelopes;
    pair<int, int> p1(1, 3);
    pair<int, int> p2(3, 5);
    pair<int, int> p3(6, 7);
    pair<int, int> p4(6, 8);
    pair<int, int> p5(8, 4);
    pair<int, int> p6(5, 9);
    envelopes.push_back(p1);
    envelopes.push_back(p2);
    envelopes.push_back(p3);
    envelopes.push_back(p4);
    envelopes.push_back(p5);
    envelopes.push_back(p6);
    Solution s;
    cout << s.maxEnvelopes(envelopes);
    return 0;
}
