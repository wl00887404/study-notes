#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0] == 1) return 0;

    int mSize = obstacleGrid.size();
    int nSize = obstacleGrid[0].size();

    int dp[mSize][nSize];
    dp[0][0] = 1;

    for (int m = 1; m < mSize; m++) {
      if (obstacleGrid[m][0]) {
        dp[m][0] = 0;
      } else {
        dp[m][0] = dp[m - 1][0];
      }
    }

    for (int n = 1; n < nSize; n++) {
      if (obstacleGrid[0][n]) {
        dp[0][n] = 0;
      } else {
        dp[0][n] = dp[0][n - 1];
      }
    }

    for (int m = 1; m < mSize; m++) {
      for (int n = 1; n < nSize; n++) {
        if (obstacleGrid[m][n]) {
          dp[m][n] = 0;
        } else {
          dp[m][n] = dp[m - 1][n] + dp[m][n - 1];
        }
      }
    }

    return dp[mSize - 1][nSize - 1];
  }
};