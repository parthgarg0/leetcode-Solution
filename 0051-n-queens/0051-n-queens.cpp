class Solution {
public:
    bool safe(vector<string>& board, int row, int col, int n) {
        for (int r = 0; r < n; r++) { // col
            if (board[r][col] == 'Q')
                return false;
        }
        for (int c = 0; c < n; c++) { // row
            if (board[row][c] == 'Q')
                return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) { // left diagonal
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) { // right diagonal
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void nqueen(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back({board});
            return;
        }

        for (int j = 0; j < n; j++) {
            if (safe(board, row, j, n)) {
                board[row][j] = 'Q';
                nqueen(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;

        nqueen(board, 0, n, ans);
        return ans;
    }
};