const int N = 1010;
class DetectSquares {
public:

    int c[N][N];
    DetectSquares() {
        memset(c, 0, sizeof c);
    }
    
    void add(vector<int> p) {
        c[p[0]][p[1]]++;
    }
    
    int count(vector<int> p) {
        int ans = 0;
        int dx[] = {1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1};
        for (int z = 0; z < 4; z++) {
            int x = p[0], y = p[1];
            while (1) {
                x += dx[z], y += dy[z];
                if (!(x >= 0 && y >= 0 && x <= 1000 && y <= 1000)) break;
                ans += c[x][y] * c[p[0]][y] * c[x][p[1]];
            }
        }
        return ans;
    }
};
