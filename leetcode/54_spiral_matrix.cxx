#include <iostream>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 *  1 11
 *  2 12
 *  3 13
 *  4 14
 *  5 15
 *  6 16
 *  7 17
 *  8 18
 *  9 19
 * 10 20
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
    if (left > right || top > bottom) return;

    if (left == right) {
      for (int i = top; i <= bottom; i++) results.push_back(matrix[i][left]);
      return;
    }

    if (top == bottom) {
      for (int i = left; i <= right; i++) results.push_back(matrix[top][i]);
      return;
    }
    
    for (int i = left; i <= right; i++) results.push_back(matrix[top][i]);
    for (int i = top + 1; i < bottom; i++) results.push_back(matrix[i][right]);
    for (int i = right; left <= i; i--) results.push_back(matrix[bottom][i]);
    for (int i = bottom - 1; top < i; i--) results.push_back(matrix[i][left]);

    spiralOrder(results, matrix, top + 1, left + 1, right - 1, bottom - 1);
  }
} solution;

int main() {
  vector<vector<int>> martix = {{1, 11}, {2, 12}, {3, 13}, {4, 14}, {5, 15},
                                {6, 16}, {7, 17}, {8, 18}, {9, 19}, {10, 20}};

  vector<int> result = solution.spiralOrder(martix);

  log(result);

  return 0;
}