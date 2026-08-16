class Solution {
public:
    void visitIsland(vector<vector<char>>& grid, int row, int col) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }
        if (grid[row][col] == '0') {
            return;
        }
        grid[row][col] = '0';
        visitIsland(grid, row - 1, col);
        visitIsland(grid, row + 1, col);
        visitIsland(grid, row, col - 1);
        visitIsland(grid, row, col + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    visitIsland(grid, i, j);
                }
            }
        }
        return count;
    }
};