/**
 * 觀察一下每個節點可以從哪個節點過來
 * [1, 0] = [0, 0]
 * [1, 1] = [0, 0]
 * [2, 0] = [1, 0]
 * [2, 1] = [1, 0], [1, 1]
 * [2, 2] = [1, 1]
 */

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp;
    int rowCount = triangle.size();

    dp.push_back({triangle[0][0]});

    for (int i = 1; i < rowCount; i++) {
      int columnCount = i + 1;

      dp.push_back(vector<int>(columnCount));

      for (int j = 0; j < columnCount; j++) {
        int value = INT_MAX;
        if (j > 0) {
          value = min(value, triangle[i][j] + dp[i - 1][j - 1]);
        }

        if (j != columnCount - 1) {
          value = min(value, triangle[i][j] + dp[i - 1][j]);
        }

        dp[i][j] = value;
      }
    }

    int result = INT_MAX;
    vector<int>& lastRow = dp[rowCount - 1];
    for (const int& value : lastRow) {
      result = min(result, value);
    }

    return result;
  }
};