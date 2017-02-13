#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++) {
            for(int k = 0; k < nums.size(); k++) {
                if(i + nums[k] <= target) dp[i + nums[k]] += dp[i];
            }
        }
        return dp[target];
    }
};
int main()
{
    Solution s;
    cout << s.combinationSum4(vector<int> a(1, 2, 3), 4);
    return 0;
}
