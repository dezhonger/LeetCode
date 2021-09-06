const int N = 100001;
int v[N + 10];
int lowbit(int x) {
    return x & (-x);
}
void add(int pos, int val) {
    for (int i = pos; i < N; i += lowbit(i)) v[i] += val;
}
int sum(int pos) {
    int s = 0;
    for (int i = pos; i > 0; i -= lowbit(i)) s += v[i];
    return s;
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        int n = a.size();
        memset(v, 0, sizeof v);
        sort(a.begin(), a.end(), [](const vector<int>& x, const vector<int>& y){
            return x[0] < y[0];
        });
        int res = 0;
        
        int all = 0;
        for (int i = n - 1; i >= 0;) {
            int j = i;
            while (j >= 0 && a[j][0] == a[i][0]) {
                int t = all - sum(a[j][1]);
                if (t > 0) res++;
                j--;
            }
            for (int k = i; k > j; k--) add(a[k][1], 1), all++;
            i = j;
        }
        return res;
    }
};
