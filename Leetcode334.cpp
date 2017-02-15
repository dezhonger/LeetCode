#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return false;
        int a = nums[0];
        int b = 0x3f3f3f3f;
        int c = 0x3f3f3f3f;
        int cnt = 1;
        for(int i = 1; i < len; i++) {
            if(cnt == 1) {
                if(nums[i] > a) b = nums[i], cnt = 2;
                else if(nums[i] < a) a = nums[i];
            }
            if(nums[i] > b) return true;
            if(nums[i] > a && nums[i] < b) b = nums[i];
            if(nums[i] > c && nums[i] < b) {
                a = c;
                b = nums[i];
                c = 0x3f3f3f3f;
            }
            if(nums[i] < a) c = nums[i];

        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout << s.increasingTriplet(v);
    return 0;
}
