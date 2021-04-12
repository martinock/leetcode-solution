class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[obstacleGrid.size()][obstacleGrid[0].size()];
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            for (int j = 0; j < obstacleGrid[i].size(); ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                
                if (i == 0) {
                    dp[i][j] = dp[i][j-1];
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
