class Solution {
public:

    void solve(vector<vector<char>>& board) {

        int rows = board.size();
        int cols = board[0].size();

        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O')
                markSafe(board, 0, j);
            if (board[rows - 1][j] == 'O')
                markSafe(board, rows - 1, j);
        }
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O')
                markSafe(board, i, 0);
            if (board[i][cols - 1] == 'O')
                markSafe(board, i, cols - 1);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
    void markSafe(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return;
        }
        if (board[row][col] != 'O') {
            return;
        }
        board[row][col] = '#';
        markSafe(board, row - 1, col);
        markSafe(board, row + 1, col);
        markSafe(board, row, col - 1);
        markSafe(board, row, col + 1);
    }
};