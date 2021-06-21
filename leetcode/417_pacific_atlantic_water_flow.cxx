#include <iostream>
#include <vector>
using namespace std;

/**
 * [
 *   [1, 2, 2, 3, 5],
 *   [3, 2, 3, 4, 4],
 *   [2, 4, 5, 3, 1],
 *   [6, 7, 1, 4, 5],
 *   [5, 1, 1, 2, 4]
 * ]
 *
 * 右上、左下是無敵的
 * 如果是最上 要看下右
 * 如果是最左 要看下右
 *
 * 1,4 往下的水流可以轉彎
 * 不能直線判端
 *
 * 有夠難
 * 真的只有暴力破解
 */

/**
 * 太平洋往右下
 * 大西洋往左上
 *
 * 兩邊往上爬回去
 * 交會的點即為答案
 */

class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int mLength = heights.size();
    int nLength = heights[0].size();
    int mLast = mLength - 1;
    int nLast = nLength - 1;

    vector<vector<int>> result;
    vector<vector<int>> isPacificReachable(mLength, vector<int>(nLength));
    vector<vector<int>> isAtlanticReachable(mLength, vector<int>(nLength));

    for (int m = 0; m < mLength; m++) {
      for (int n = 0; n < nLength; n++) {
        isPacificReachable[m][n] = 0;
        isAtlanticReachable[m][n] = 0;
      }
    }

    for (int m = 0; m < mLength; m++) {
      checkReachable(heights, isPacificReachable, m, 0, mLength, nLength);
      checkReachable(heights, isAtlanticReachable, m, nLast, mLength, nLength);
    }

    for (int n = 0; n < nLength; n++) {
      checkReachable(heights, isPacificReachable, 0, n, mLength, nLength);
      checkReachable(heights, isAtlanticReachable, mLast, n, mLength, nLength);
    }

    for (int m = 0; m < mLength; m++) {
      for (int n = 0; n < nLength; n++) {
        if (!isPacificReachable[m][n] || !isAtlanticReachable[m][n]) continue;
        result.push_back({m, n});
      }
    }

    return result;
  }

 private:
  void checkReachable(vector<vector<int>>& heights,
                      vector<vector<int>>& isReachable, int m, int n,
                      int& mLength, int& nLength) {
    if (isReachable[m][n] == 1) return;

    isReachable[m][n] = 1;
    if (0 <= m - 1 && heights[m - 1][n] >= heights[m][n]) {
      checkReachable(heights, isReachable, m - 1, n, mLength, nLength);
    }
    if (m + 1 < mLength && heights[m + 1][n] >= heights[m][n]) {
      checkReachable(heights, isReachable, m + 1, n, mLength, nLength);
    }
    if (0 <= n - 1 && heights[m][n - 1] >= heights[m][n]) {
      checkReachable(heights, isReachable, m, n - 1, mLength, nLength);
    }
    if (n + 1 < nLength && heights[m][n + 1] >= heights[m][n]) {
      checkReachable(heights, isReachable, m, n + 1, mLength, nLength);
    }
  };
} solution;

int main() {
  vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                 {3, 2, 3, 4, 4},
                                 {2, 4, 5, 3, 1},
                                 {6, 7, 1, 4, 5},
                                 {5, 1, 1, 2, 4}};

  vector<vector<int>> result =

      solution.pacificAtlantic(heights);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i][0] << " " << result[i][1] << endl;
  }

  return 0;
}