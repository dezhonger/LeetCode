class Solution {
public:
    int n, m;
    bool check1(int x, int y, vector<vector<char>>& board, string& w) {
        int sz = w.size();
        if (x + sz - 1 >= n) return false;
        int e = x + sz;
        if (x > 0 && (board[x - 1][y] == ' ' || islower(board[x - 1][y]))) return false;
        if (e < n && (board[e][y] == ' ' || islower(board[e][y]))) return false;
        for (int k = x, i = 0; i < sz; i++, k++) {
            if (!(board[k][y] == w[i] || board[k][y] == ' ')) return false;
        }
        return true;
    }
    
    bool check2(int x, int y, vector<vector<char>>& board, string& w) {
        int sz = w.size();
        if (x - sz + 1 < 0) return false;
        int e = x - sz;
        if (x + 1 < n && (board[x + 1][y] == ' ' || islower(board[x + 1][y]))) return false;
        if (e >= 0 && (board[e][y] == ' ' || islower(board[e][y]))) return false;
        for (int k = x, i = 0; i < sz; i++, k--) {
            if (!(board[k][y] == w[i] || board[k][y] == ' ')) return false;
        }
        return true;
    }
    
    bool check3(int x, int y, vector<vector<char>>& board, string& w) {
        int sz = w.size();
        if (y + sz - 1 >= m) return false;
        int e = y + sz;
        if (y > 0 && (board[x][y - 1] == ' ' || islower(board[x][y - 1]))) return false;
        if (e < m && (board[x][e] == ' ' || islower(board[x][e]))) return false;
        for (int k = y, i = 0; i < sz; i++, k++) {
            if (!(board[x][k] == w[i] || board[x][k] == ' ')) return false;
        }
        return true;
    }
    
    bool check4(int x, int y, vector<vector<char>>& board, string& w) {
        int sz = w.size();
        if (y - sz + 1 < 0) return false;
        int e = y - sz;
        if (y + 1 < m && (board[x][y + 1] == ' ' || islower(board[x][y + 1]))) return false;
        if (e >= 0 && (board[x][e] == ' ' || islower(board[x][e]))) return false;
        for (int k = y, i = 0; i < sz; i++, k--) {
            if (!(board[x][k] == w[i] || board[x][k] == ' ')) return false;
        }
        return true;
    }

    bool placeWordInCrossword(vector<vector<char>>& board, string w) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == w[0] || board[i][j] == ' ') {
                    // 可以作为起点
                    // 枚举四种情况，看是否成立
                    if (check1(i, j, board, w)) return true;
                    if (check2(i, j, board, w)) return true;
                    if (check3(i, j, board, w)) return true;
                    if (check4(i, j, board, w)) return true;
                }
            }
        }
        return false;
    }
};
