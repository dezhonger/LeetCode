template<typename T, typename S>
inline bool upmin(T &a, const S &b) { return a > b ? a = b, 1 : 0; }

template<typename T, typename S>
inline bool upmax(T &a, const S &b) { return a < b ? a = b, 1 : 0; }


typedef long long LL;
LL mod = (int)1e9 + 7;

const int N = 3000010;
class Solution {
public:

    //下面是暴力做法
    int boxDelivering_bruteforce(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        // f[i] = min(f[j], cal(j + 1, j + 2...i));
        int n = boxes.size(), ans = -1e8;
        vector<int> dsum(n + 1), f(n + 1);
        vector<LL> wsum(n + 1);
        for (int i = 0; i < n; i++) wsum[i + 1] = wsum[i] + boxes[i][1];
        for (int i = 2; i <= n; i++) {
            int d = boxes[i - 1][0] != boxes[i - 2][0];
            dsum[i] = dsum[i - 1] + d;
        }
        for (int i = 1; i <= n; i++) {
            f[i] = 1e8;
            for (int j = i - 1; j >= max(0, i - maxBoxes) && (wsum[i] - wsum[j] <= maxWeight); j--) {
                //[j + 1, j + 2... i] 作为新的一批
                int l = j + 1, r = i;
                upmin(f[i], f[j] + dsum[r] - dsum[l] + 2);
            }
        }
            
        return f[n];
    }
    
    
    // 优化后单调队列的做法 O(N)
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        // f[i] = min(f[j], cal(j + 1, j + 2...i));
        int n = boxes.size(), ans = -1e8;
        vector<int> dsum(n + 2), f(n + 1);
        vector<LL> wsum(n + 1);
        for (int i = 0; i < n; i++) wsum[i + 1] = wsum[i] + boxes[i][1];
        for (int i = 2; i <= n; i++) {
            int d = boxes[i - 1][0] != boxes[i - 2][0];
            dsum[i] = dsum[i - 1] + d;
        }
        
        //维护一个单调递增的队列下标v，满足f[v] - dsum[v]递增
        deque<int> q;
        q.push_back(0);
        for (int i = 1; i <= n; i++) {
            f[i] = 1e8;
            // f[i] = min(f[j] + dsum[i] - dsum[j + 1] + 2)) = dsum[i] + 2 + min(f[j] - dsum[j + 1]);
            while (q.size() && (wsum[i] - wsum[q.front()] > maxWeight || i - q.front() > maxBoxes)) q.pop_front();
            f[i] = dsum[i] + 2 + f[q.front()] - dsum[q.front() + 1];
            int cur = f[i] - dsum[i + 1];
            while (q.size() && cur < f[q.back()] - dsum[q.back() + 1]) q.pop_back();
            q.push_back(i);
        }
        return f[n];
    }
};
