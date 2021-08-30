typedef long long LL;
typedef pair<int, int> PII;
LL mod = (int)1e9 + 7;

// LL powmod(LL a,LL b) { LL res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = res * a % mod; a = a * a % mod; } return res; }

// int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

const int N = 1010;
int f[N][N];

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) f[i][j] = 1;
                else f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
                f[i][j] %= mod;
            }
        }
        int res = cal(nums);
        return (res - 1 + mod) % mod;
    }
    
    int cal(vector<int>& nums) {
        if (nums.size() <= 1) return 1;
        int a = 0, b = 0;
        vector<int> v1, v2;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[0]) a++, v1.push_back(nums[i]);
            else b++, v2.push_back(nums[i]);
        }
        return (1LL * f[a + b][a] * cal(v1) % mod )* cal(v2) % mod;
    }
};
