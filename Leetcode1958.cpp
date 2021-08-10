int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

class Solution {
public:
    bool check(int x, int y) {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int s = 'W' + 'B';
        for (int i = 0; i < 8; i++) {
            int x = rMove, y = cMove;
            int len = 0;
            while (check(x + dx[i], y + dy[i]) && board[x + dx[i]][y + dy[i]] == s - color) {
                x += dx[i];
                y += dy[i];
                len++;
            }
            if (len && (check(x + dx[i], y + dy[i]) && board[x + dx[i]][y + dy[i]] == color)) return true;
        }
        return false;
    }
};
