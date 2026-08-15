class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                char number = board[row][col];
                for (int j = 0; j < 9; j++) {
                    if (j != col && board[row][j] == number)
                        return false;
                }
                for (int i = 0; i < 9; i++) {
                    if (i != row && board[i][col] == number)
                        return false;
                }
                int startRow = (row / 3) * 3;
                int startCol = (col / 3) * 3;
                for (int i = startRow; i < startRow + 3; i++) {
                    for (int j = startCol; j < startCol + 3; j++) {
                        if ((i != row || j != col) &&
                            board[i][j] == number) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};