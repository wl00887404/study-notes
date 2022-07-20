#include <iostream>
#include <vector>

using namespace std;

/**
 * 類似題是 200
 * 很有即視感，果然做過呢
 */

class Solution {
 public:
  vector<vector<int>>* gridPointer;
  int m;
  int n;
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    gridPointer = &grid;
    m = grid.size();
    n = grid[0].size();
    int result = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        result = max(result, getArea(i, j));
      }
    }

    return result;
  }

  int getArea(int i, int j) {
    if (i < 0 || j < 0 || i == m || j == n) return 0;
    vector<vector<int>>& grid = *gridPointer;

    if (grid[i][j] == 0) return 0;

    grid[i][j] = 0;

    return 1 + getArea(i - 1, j) + getArea(i + 1, j) + getArea(i, j - 1) +
           getArea(i, j + 1);
  }
};