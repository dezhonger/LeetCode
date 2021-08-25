class Solution {
public:
    int minimumBoxes(int n) {
        //a[i] = i * (i + 1) / 2
        //s = sigma  a[i];
        int i = 1, s = 0, remain = 0, t = 0;
        int ans = 0;
        for (int i = 1, j = 1; ;i++, j += i) {
            if (s + j == n) return j;
            else if (s + j > n) {
                remain = n - s;
                ans = j - i;
                break;
            }
            s += j;
            
        }
        for (int j = 1; ;j++) {
            if (j * (j + 1) / 2 >= remain) return j + ans;
        }
        return -1;
    }
};
