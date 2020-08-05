#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
		LL dp1[len1 + 10];
		LL dp2[len2 + 10];
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		LL ans = 0;
		int x = 0, y = 0;
		while (x < len1 || y < len2) {
			while ( x < len1 && y < len2) {
				LL xx = nums1[x];
				LL yy = nums2[y];
				if (xx < yy) {
					dp1[x + 1] = max(dp1[x + 1], dp1[x] + nums1[x]);
					ans = max(ans, dp1[x + 1]);
					x++;
				} else if (xx > yy) {
					dp2[y + 1] = max(dp2[y + 1], dp2[y] + nums2[y]);
					ans = max(ans, dp2[y + 1]);
					y++;
				} else {
					dp1[x+1] = max(dp1[x+1], dp1[x] + nums1[x]);
					dp2[y+1] = max(dp2[y+1], dp2[y] + nums2[y]);
					dp1[x+1] = max(dp1[x+1], dp2[y+1]);
					dp2[y+1] = max(dp1[x+1], dp2[y+1]);
					ans = max(ans, dp1[x+1]);
					x++;
					y++;
				}
			}
			while (x < len1) {
				int xx = nums1[x];
				dp1[x + 1] = max(dp1[x + 1], dp1[x] + xx);
				ans = max(ans, dp1[x + 1]);
				x++;
			}
			while (y < len2) {
				int yy = nums2[y];
				dp2[y + 1] = max(dp2[y + 1], dp2[y] + yy);
				ans = max(ans, dp2[y + 1]);
				y++;
			}

		}
		return ans % 1000000007;
    }
};

