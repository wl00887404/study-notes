
#include <iostream>
#include <vector>

using namespace std;

#define LAND 1
#define SEA 0

class Solution {
 public:
  int numEnclaves(vector<vector<int>>& grid) {
    gridPointer = &grid;
    m = grid.size();
    n = grid[0].size();

    for (int i = 0; i < m; i++) {
      calcIsland(i, 0);
      calcIsland(i, n - 1);
    }

    for (int j = 1; j < n - 1; j++) {
      calcIsland(0, j);
      calcIsland(m - 1, j);
    }

    int result = 0;
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (grid[i][j] == SEA) continue;

        result += calcIsland(i, j);
      }
    }

    return result;
  }

  vector<vector<int>>* gridPointer;
  int m;
  int n;

  int calcIsland(int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return 0;

    vector<vector<int>>& grid = *gridPointer;
    if (grid[i][j] == SEA) return 0;

    grid[i][j] = SEA;
    return 1 + calcIsland(i - 1, j) + calcIsland(i, j - 1) +
           calcIsland(i + 1, j) + calcIsland(i, j + 1);
  }
};