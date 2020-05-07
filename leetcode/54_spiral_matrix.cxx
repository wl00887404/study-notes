#include <iostream>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 * 1 2 3
 * 4 5 6
 *
 * 1 2 3 6 5 4
 *
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *
 * 1 2 3 6 9 8 7 4 5
 *
 *  1  2  3
 *  4  5  6
 *  7  8  9
 * 10 11 12
 *
 * 1 2 3 6 9 12 11 10 7 4 5 8
 */

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int height = matrix.size();

    if (height == 0) return {};

    vector<int> results;

    spiralOrder(results, matrix, 0, 0, matrix[0].size() - 1, height - 1);

    return results;
  }

  void spiralOrder(vector<int>& results, vector<vector<int>>& matrix, int top,
                   int left, int right, int bottom) {
    if (left == right) {
      if (top == bottom) return results.push_back(matrix[top][left]);

      for (int i = top; i <= bottom; i++) results.push_back(matrix[i][left]);
      return;
    }

    if (top == bottom) {
      for (int i = left; i <= right; i++) results.push_back(matrix[top][i]);
      return;
    }

    for (int i = left; i < right; i++) {
      results.push_back(matrix[top][i]);
    }

    for (int i = top; i < bottom; i++) {
      results.push_back(matrix[i][right]);
    }

    for (int i = right; i > 0; i--) {
      results.push_back(matrix[bottom][i]);
    }

    for (int i = bottom; i > 0; i--) {
      results.push_back(matrix[i][left]);
    }

    spiralOrder(results, matrix, top + 1, left + 1, right - 1, bottom - 1);
  }
} solution;

int main() {
  vector<vector<int>> martix = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
  };

  vector<int> result = solution.spiralOrder(martix);

  log(result);

  return 0;
}