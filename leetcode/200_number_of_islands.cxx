#include <iostream>
#include <vector>
using namespace std;

/**
 * TODO: 敢不敢再快一點
 * 好像跟 417 類似
 */

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    int yLength = grid.size();
    int xLength = grid[0].size();

    for (int y = 0; y < yLength; y++) {
      for (int x = 0; x < xLength; x++) {
        if (grid[y][x] == '0') continue;
        result++;
       destroyIsland(grid, y, x, yLength, xLength);
      }
    }

    return result;
  }

 private:
  void destroyIsland(vector<vector<char>>& grid, int& y, int& x, int& yLength,
                     int& xLength) {
    grid[y][x] = '0';
    int top = y - 1;
    int bottom = y + 1;
    int left = x - 1;
    int right = x + 1;

    if (top >= 0 && grid[top][x] == '1') {
      destroyIsland(grid, top, x, yLength, xLength);
    }
    if (bottom < yLength && grid[bottom][x] == '1') {
      destroyIsland(grid, bottom, x, yLength, xLength);
    }
    if (left >= 0 && grid[y][left] == '1') {
      destroyIsland(grid, y, left, yLength, xLength);
    }
    if (right < xLength && grid[y][right] == '1') {
      destroyIsland(grid, y, right, yLength, xLength);
    }
  }
} solution;

int main() {
  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};
  solution.numIslands(grid);
  return 0;
}