#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int result = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) continue;

        if (get(grid, i - 1, j) == 0) result++;
        if (get(grid, i + 1, j) == 0) result++;
        if (get(grid, i, j - 1) == 0) result++;
        if (get(grid, i, j + 1) == 0) result++;
      }
    }

    return result;
  }

  int get(vector<vector<int>>& grid, int i, int j) {
    try {
      return grid.at(i).at(j);
    } catch (const out_of_range& error) {
      return 0;
    }
  }
};