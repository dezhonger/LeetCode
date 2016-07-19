#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dp[1010];
    int dfs(int index, vector<int>& nums) {
        if(dp[index] != 0) return dp[index];
        dp[index] = 1;
        for(int i = index - 1; i >= 0; i--) {
            if(nums[index] % nums[i] == 0) {
                dp[index] = max(dp[index], dfs(i, nums) + 1);
            }
        }

//        cout << index << " " << dp[index] << endl;
        return dp[index];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> vv;
        for(int i = 0; i < nums.size(); i++) dp[i] = 0;
        sort(nums.begin(), nums.end());
        int ans = 0, xiabiao = 0;
        for(int i = 0; i < nums.size(); i++) {
            int t = dfs(i, nums);
            if(t > ans) {
                ans = t;
                xiabiao = i;
            }
        }
        vv.push_back(nums[xiabiao]);
        for(int k = xiabiao - 1; k >= 0; k--) {
            if(dp[k] + 1 == ans) {
                ans--;
                vv.push_back(nums[k]);
            }
        }
        return vv;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);


    v = s.largestDivisibleSubset(v);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    return 0;
}
