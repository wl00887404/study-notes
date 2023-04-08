#include <iostream>
#include <vector>

using namespace std;

#define LAND 0
#define SEA 1

/**
 * 1 是水 0 是島
 * 找島嶼外面全是水
 * 總之就是往外擴張，要是碰邊界就不能算 closed
 */

class Solution {
 public:
  int closedIsland(vector<vector<int>>& grid) {
    gridPointer = &grid;
    m = grid.size();
    n = grid[0].size();

    for (int i = 0; i < m; i++) {
      killIsland(i, 0);
      killIsland(i, n - 1);
    }

    for (int j = 1; j < n - 1; j++) {
      killIsland(0, j);
      killIsland(m - 1, j);
    }

    int result = 0;
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (grid[i][j] == SEA) continue;

        result++;
        killIsland(i, j);
      }
    }

    return result;
  }

  vector<vector<int>>* gridPointer;
  int m;
  int n;

  void killIsland(int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return;

    vector<vector<int>>& grid = *gridPointer;
    if (grid[i][j] == SEA) return;

    grid[i][j] = SEA;
    killIsland(i - 1, j);
    killIsland(i, j - 1);
    killIsland(i + 1, j);
    killIsland(i, j + 1);
  }
};