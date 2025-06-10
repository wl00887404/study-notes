#include <iostream>
#include <vector>
using namespace std;

/**
 * 給定一個 m * n 的 grid
 * 可以從任何一個格子開始，只有往右上、往右、往右下，三個方向移動
 * 而且移動到的格子，一定要比自己所在的格子還大
 */
class Solution {
 public:
  int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> cache;

    cache.resize(m, vector<int>(n, 0));
    int result = 0;

    for (int j = n - 2; j >= 0; j--) {
      for (int i = 0; i < m; i++) {
        // 可以往右上移動
        if (i - 1 >= 0 && grid[i][j] < grid[i - 1][j + 1]) {
          cache[i][j] = max(cache[i][j], 1 + cache[i - 1][j + 1]);
        }

        // 可以往右移動
        if (grid[i][j] < grid[i][j + 1]) {
          cache[i][j] = max(cache[i][j], 1 + cache[i][j + 1]);
        }

        // 可以往右下移動
        if (i + 1 < m && grid[i][j] < grid[i + 1][j + 1]) {
          cache[i][j] = max(cache[i][j], 1 + cache[i + 1][j + 1]);
        }

        if (j == 0) {
          result = max(result, cache[i][0]);
        }
      }
    }

    return result;
  }
};