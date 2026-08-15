class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> paths(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] == 1)
            return 0;

        paths[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (obstacleGrid[i][j] == 1) {
                    paths[i][j] = 0;
                }
                else {
                    if (i > 0)
                        paths[i][j] += paths[i - 1][j];
                    if (j > 0)
                        paths[i][j] += paths[i][j - 1];
                }
            }
        }
        return paths[m - 1][n - 1];
    }
};