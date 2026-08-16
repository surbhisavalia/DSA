class Solution {
public:

    int solve(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if(i >= m || j >= n) return 0;
        if(matrix[i][j] == '0') return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int right = solve(matrix, i, j + 1, dp);
        int down = solve(matrix, i + 1, j, dp);
        int diagonal = solve(matrix, i + 1, j + 1, dp);

        return dp[i][j] = 1 + min({right, down, diagonal});
    }

    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>dp(m, vector(n, -1));

        int maxi = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int side = solve(matrix, i, j, dp);
                maxi = max(maxi, side);
            }
        }
        return maxi * maxi;
    }
};