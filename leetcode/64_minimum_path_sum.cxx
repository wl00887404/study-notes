#include <iostream>
#include <vector>

using namespace std;

/**
 * 老題目從上面來或左邊來
 * 就每個格子選一個最小的來源就好
 * 不知道難在哪裡
 * 與 62 、 174 關聯
 */

/**
 * 2023/5/27 又寫了一次
 */

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int dp[m][n];
    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < n; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[m - 1][n - 1];
  }
};