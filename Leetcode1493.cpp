#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int update(int l, int r, int zero) {
		//zero = 1;
		if (zero > 0) return r - l + 1 - zero;
		else return r - l;
	}

    int longestSubarray(vector<int>& nums) {
		int ans = 0;
		int sz = nums.size();
		int l = 0;
		
		int zero = 0;
		for (int r = l; r < sz; r++) {
			if (nums[r] == 0) {
				zero++;
				if (zero == 1) {
					ans = max(ans, update(l, r, zero));
				}
				else {
					while (l <= r && zero > 1) {
						if (nums[l++] == 0) {
							zero--;
						}
					}
					ans = max(ans, update(l, r, zero));
				}
			} else {
				ans = max(ans, update(l, r, zero));
			}
		}
		return ans;
    }
};

int main() {
	Solution sol;
	vector<int> nums = {0,0,1,1};
	cout << sol.longestSubarray(nums);
	return 0;
}