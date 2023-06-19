#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 題目是可以上下左右走
 * 找到所以嚴格遞增的路徑
 *
 * 找到一條路徑
 * 從長度直接推算子路徑的數量好像有點不切實際
 * 如果路徑有重複，那就不好處理
 * [
 *   [1, 1, 1, 1],
 *   [2, 3, 4, 5],
 *   [1, 1, 1, 1],
 * ]
 *
 * 其中 [1, 2, 3, 4, 5] 有兩個開頭
 * 但是其中 [2, 3, 4, 5] 是重複的
 * 欸來是不要算中間，一律用開頭來算
 * [1, 2, 3, 4, 5] 可以知道 2, 3, 4, 5 也是遞增路徑
 * grid[0][0] 結果是 5
 * 也就是表示 [1, 1] [1, 2] [1, 3] [1, 4] [1, 5]
 */

class Solution {
 public:
  int m;
  int n;
  vector<vector<int>> longestLengths;
  vector<vector<int>>* gridPointer;
  int mod = 1e9 + 7;

  int countPaths(vector<vector<int>>& grid) {
    int result = 0;
    m = grid.size();
    n = grid[0].size();
    gridPointer = &grid;
    longestLengths.resize(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        result += getLongestLengths(i, j);
        result %= mod;
      }
    }

    return result;
  }

  int getLongestLengths(int i, int j) {
    if (longestLengths[i][j] != -1) return longestLengths[i][j];

    vector<vector<int>>& grid = *gridPointer;
    longestLengths[i][j] = 1;
    if (i - 1 >= 0 && grid[i - 1][j] > grid[i][j]) {
      longestLengths[i][j] += getLongestLengths(i - 1, j);
    }
    if (i + 1 < m && grid[i + 1][j] > grid[i][j]) {
      longestLengths[i][j] += getLongestLengths(i + 1, j);
    }
    if (j - 1 >= 0 && grid[i][j - 1] > grid[i][j]) {
      longestLengths[i][j] += getLongestLengths(i, j - 1);
    }
    if (j + 1 < n && grid[i][j + 1] > grid[i][j]) {
      longestLengths[i][j] += getLongestLengths(i, j + 1);
    }
    longestLengths[i][j] %= mod;

    return longestLengths[i][j];
  }
};