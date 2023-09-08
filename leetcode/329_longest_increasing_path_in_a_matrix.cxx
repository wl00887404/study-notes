#include <iostream>
#include <vector>

using namespace std;

/**
 * 每個點紀錄自己的 increasingPath
 * 因為 increaseing 所以有方向性不可能回頭
 *
 * 每個點的 increasingPath 是
 * 上下左右比自己高的 1 + increasingPath
 */

/**
 * 這題還挺簡單的
 * 覺得沒有 hard
 */

class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();
    matrixPointer = &matrix;

    isDone.resize(m, vector<bool>(n, false));
    values.resize(m, vector<int>(n, 1));

    int result = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        result = max(result, helper(i, j));
      }
    }

    return result;
  }

  int helper(int i, int j) {
    if (isDone[i][j]) return values[i][j];

    vector<vector<int>>& matrix = *matrixPointer;

    int nextValue = values[i][j];
    if (i + 1 < m && matrix[i + 1][j] > matrix[i][j]) {
      nextValue = max(nextValue, values[i][j] + helper(i + 1, j));
    }

    if (0 <= i - 1 && matrix[i - 1][j] > matrix[i][j]) {
      nextValue = max(nextValue, values[i][j] + helper(i - 1, j));
    }

    if (j + 1 < n && matrix[i][j + 1] > matrix[i][j]) {
      nextValue = max(nextValue, values[i][j] + helper(i, j + 1));
    }

    if (0 <= j - 1 && matrix[i][j - 1] > matrix[i][j]) {
      nextValue = max(nextValue, values[i][j] + helper(i, j - 1));
    }

    values[i][j] = nextValue;
    isDone[i][j] = true;

    return values[i][j];
  }

  int m;
  int n;
  vector<vector<bool>> isDone;
  vector<vector<int>> values;
  vector<vector<int>>* matrixPointer;
};