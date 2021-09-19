#include <iostream>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 * 2021/9/16 Daily 挑戰的題目
 * 其實就毫無變化的剝洋蔥
 */

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int height = matrix.size();

    if (height == 0) return {};

    vector<int> results;

    // top, left 包含
    // right, bottom 不包含
    spiralOrder(results, matrix, 0, 0, matrix[0].size(), height);

    return results;
  }

  void spiralOrder(vector<int>& results, vector<vector<int>>& matrix, int top,
                   int left, int right, int bottom) {
    if (left >= right || top >= bottom) return;

    // 只剩垂直的一行
    if (right - left == 1) {
      for (int i = top; i < bottom; i++) results.push_back(matrix[i][left]);
      return;
    }

    // 只剩水平的一行
    if (bottom - top == 1) {
      for (int i = left; i < right; i++) results.push_back(matrix[top][i]);
      return;
    }

    for (int i = left; i < right; i++) {
      results.push_back(matrix[top][i]);
    }
    for (int i = top + 1; i < bottom; i++) {
      results.push_back(matrix[i][right - 1]);
    }
    for (int i = right - 2; left <= i; i--) {
      results.push_back(matrix[bottom - 1][i]);
    }
    for (int i = bottom - 2; top < i; i--) {
      results.push_back(matrix[i][left]);
    }

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