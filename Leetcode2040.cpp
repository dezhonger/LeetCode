typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }


class Solution {
public:
    LL cal(LL val, vector<int>& nums1, vector<int>& nums2) {
        //c: the number of less or equals val
        LL c = 0;
        for (LL x: nums1) {
            if (x == 0) {
                if (val >= 0) c += nums2.size();
            } else if (x > 0) {
                if (x * nums2[0] > val) continue;
                int l = 0, r = nums2.size() - 1;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    LL t = x * nums2[mid];
                    if (t > val) r = mid - 1;
                    else l = mid;
                }
                c += l + 1;
            } else {
                if (x * nums2[nums2.size() - 1] > val) continue;
                int l = 0, r = nums2.size() - 1;
                while (l < r) {
                    int mid = l + r >> 1;
                    LL t = x * nums2[mid];
                    if (t > val) l = mid + 1;
                    else r = mid;
                }
                c += nums2.size() - l;
            }
        }
        return c;
    }

    LL kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        LL l = -1e11, r = 1e11;
        while (l < r) {
            LL mid = l + r >> 1;
            LL cnt = cal(mid, nums1, nums2);
            if (cnt >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
