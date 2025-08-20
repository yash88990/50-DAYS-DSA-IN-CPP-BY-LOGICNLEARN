class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        // First row or first column can only have 1x1 squares
                        dp[i][j] = 1;
                    } else {
                        // Check the minimum of top, left, and top-left cells, then add 1
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                    // Add to the total count
                    count += dp[i][j];
                }
            }
        }

        return count;
    }
};